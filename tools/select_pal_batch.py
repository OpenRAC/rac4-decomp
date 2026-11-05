#!/usr/bin/env python3
"""Select and claim a batch of PAL functions for a later agent prompt.

Run from the repository root:

    venv/Scripts/python.exe tools/select_pal_batch.py --owner paseo
    venv/Scripts/python.exe tools/select_pal_batch.py --owner paseo --dry-run

The default selection is 50 functions. Repeating the command with the same
owner and manifest returns the existing selection instead of choosing a new one.
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import claims  # noqa: E402
import levels  # noqa: E402
import progress  # noqa: E402

FUNC_RE = re.compile(r"func_[0-9A-F]{8}")
OWNER_RE = re.compile(r"[A-Za-z0-9_.:-]+")


def previous_function_names() -> set[str]:
    names: set[str] = set()
    paths = list(ROOT.glob("build/batch*/**/*.json")) + list(ROOT.glob("build/orchestrator/**/*.json"))
    for path in paths:
        try:
            data = json.loads(path.read_text())
        except (OSError, ValueError):
            continue

        def walk(value):
            if isinstance(value, dict):
                for key, item in value.items():
                    if key in ("name", "candidate", "function") and isinstance(item, str):
                        match = FUNC_RE.search(item)
                        if match:
                            names.add(match.group(0))
                    else:
                        walk(item)
            elif isinstance(value, list):
                for item in value:
                    walk(item)

        walk(data)
    return names


def select_functions(pool_path: Path, count: int) -> list[dict]:
    levels.select("pal")
    core, _, shared, own = progress.state()
    done = {
        function["name"]
        for function in core + shared + [f for functions in own.values() for f in functions]
        if function["done"]
    }
    previous = previous_function_names()
    pool = json.loads(pool_path.read_text())
    available = []
    family_prefixes = ("func_0048C", "func_0043D", "func_004CD", "func_0054A")
    for original in pool:
        name = original["name"]
        if name in done or name in previous or claims.holder(name):
            continue
        if not 32 <= original["size"] <= 900:
            continue
        source = ROOT / "src" / "pal" / "game" / (name[5:] + ".c")
        if source.exists():
            continue
        family = next((prefix for prefix in family_prefixes if name.startswith(prefix)), None)
        row = dict(original, claim=claims.holder(name), source=None, family=family, previous_attempt=None)
        available.append(row)
    available.sort(key=lambda row: (row["family"] is None, abs(row["size"] - 192), row["size"], row["name"]))
    if len(available) < count:
        raise SystemExit(f"Only {len(available)} eligible functions remain; {count} requested")
    return available[:count]


def write_json(path: Path, data) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix(path.suffix + ".tmp")
    temporary.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8", newline="\n")
    temporary.replace(path)


def existing_selection(path: Path, owner: str, count: int) -> list[dict] | None:
    if not path.exists():
        return None
    data = json.loads(path.read_text())
    functions = data.get("functions", [])
    if data.get("owner") != owner or len(functions) != count:
        raise SystemExit(f"Existing manifest {path} belongs to another selection; choose another owner or output path")
    if any(claims.holder(row["name"]) != owner for row in functions):
        raise SystemExit(f"Existing manifest {path} has missing or foreign claims; choose another owner or output path")
    return functions


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--owner", default="paseo", help="Claim owner recorded in build/claims (default: paseo)")
    parser.add_argument("--count", type=int, default=50, help="Number of functions (default: 50)")
    parser.add_argument("--pool", default="build/large56/pool.json", help="Curated candidate pool")
    parser.add_argument("--output", default="build/selected_batch.json", help="Manifest to write")
    parser.add_argument("--text-output", default="build/selected_batch.txt", help="Plain function-name list")
    parser.add_argument("--dry-run", action="store_true", help="Select without claiming")
    args = parser.parse_args()
    if not OWNER_RE.fullmatch(args.owner):
        parser.error("Owner must contain only letters, digits, dots, underscores, colons or dashes")
    if args.count < 1:
        parser.error("Count must be positive")

    output = ROOT / args.output
    text_output = ROOT / args.text_output
    if not args.dry_run and existing_selection(output, args.owner, args.count) is not None:
        print(f"Using existing selection: {args.output} ({args.count} functions, owner {args.owner})")
        return

    selected = select_functions(ROOT / args.pool, args.count)
    newly_claimed = []
    try:
        for row in selected:
            name = row["name"]
            if not args.dry_run:
                if not claims.claim(args.owner, name):
                    raise RuntimeError(f"{name} is claimed by {claims.holder(name)}")
                newly_claimed.append(name)
            row["status"] = "selected" if args.dry_run else "claimed"
            row["claim"] = None if args.dry_run else args.owner
    except Exception:
        for name in newly_claimed:
            claims.release(args.owner, name)
        raise

    document = {
        "version": 1,
        "owner": args.owner,
        "count": len(selected),
        "bytes": sum(row["size"] for row in selected),
        "dry_run": args.dry_run,
        "functions": selected,
    }
    try:
        write_json(output, document)
        text_output.parent.mkdir(parents=True, exist_ok=True)
        text_output.write_text("\n".join(row["name"] for row in selected) + "\n", encoding="utf-8", newline="\n")
    except Exception:
        for name in newly_claimed:
            claims.release(args.owner, name)
        raise

    action = "Selected" if args.dry_run else "Selected and claimed"
    print(f"{action} {len(selected)} functions ({document['bytes']} bytes) for {args.owner}")
    print(f"Manifest: {args.output}")
    print(f"Names: {args.text_output}")


if __name__ == "__main__":
    main()
