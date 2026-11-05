#!/usr/bin/env python3
"""Prepare, launch and collect small PAL decompilation agent batches.

    prepare --owner paseo [--agents 3] [--count 50] [--dry-run]
    launch --owner paseo --provider PROVIDER [--dry-run]
    status --owner paseo
    collect --owner paseo

The launcher uses `paseo run` when it is available. No game build is run.
"""
from __future__ import annotations

import argparse
import json
import os
import shlex
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import claims  # noqa: E402
import select_pal_batch  # noqa: E402

OWNER_RE = select_pal_batch.OWNER_RE


def batch_dir(owner: str) -> Path:
    return ROOT / "build/orchestrator" / owner


def selection_path(owner: str) -> Path:
    return batch_dir(owner) / "selection.json"


def manifest_path(owner: str, agent: str) -> Path:
    return batch_dir(owner) / (agent + "-matches.json")


def prompt_for(owner: str, agent: str) -> str:
    manifest = f"build/orchestrator/{owner}/{agent}.json"
    results = f"build/orchestrator/{owner}/{agent}-matches.json"
    return (
        f"Work in C:/nativeBuilds/rac4-decomp on PAL functions listed only in {manifest}. "
        f"Use owner {owner}-{agent}; claim before work and use the landing lock. "
        "First read C:/nativeBuilds/KIMI_RAC4_DECOMP_ANLEITUNG.md completely and follow it. "
        "Read C:/nativeBuilds/RAC4_PAL_FUNKTIONSVERTRAEGE.json, config/pal/function_signatures.json "
        "and config/pal/signatures.tsv before drafting; both external files are read-only. "
        "Prefer understood loader, interpolation and UI families and complete small C functions. "
        "Do not retry documented fragments, stopped near-misses or allocator walls without new evidence. "
        "For each variant state one concrete hypothesis. Normally use a first draft plus 2-3 corrections; "
        "8 variants is the absolute limit only with new evidence. Stop after 2-3 identical emissions, "
        "document the best result and release the claim. Use the unchanged cc.sh pipeline and "
        "build/check_pal_candidate.py. Require a direct MATCH plus ABI, actual relocation targets, "
        "jump tables, initializers, output initialization and semantic review. No inline assembly, "
        "artificial barriers, unproven volatile or invented initializers. Recheck only new or changed "
        "functions, never the whole unchanged manifest after each match. Record the exact final source "
        f"SHA-256 and compact evidence in {results}. Do not run a full build, change maps or commit. "
        "Use small assembly/caller excerpts and save reusable evidence instead of loading large generated "
        "C++ files or repeating documentation. Never spawn subagents or additional packages: you are one "
        "of at most three workers total. Work through your assigned functions yourself."
    )


def prepare(owner: str, count: int, agent_count: int, dry_run: bool) -> None:
    output = selection_path(owner)
    if output.exists():
        data = json.loads(output.read_text())
        functions = data["functions"]
        if len(functions) != count:
            raise SystemExit("Existing selection has a different function count; choose another owner")
        if not dry_run and any(claims.holder(row["name"]) not in (None, owner) for row in functions):
            raise SystemExit("Existing selection has foreign claims")
        if not dry_run:
            for row in functions:
                if not claims.claim(owner, row["name"]):
                    raise SystemExit(f"Claim is held by {claims.holder(row['name'])}")
        for row in functions:
            row["status"] = "selected" if dry_run else "claimed"
            row["claim"] = None if dry_run else owner
        data["dry_run"] = dry_run
        directory = batch_dir(owner)
        agents = [chr(ord("a") + index) for index in range(agent_count)]
        for index, agent in enumerate(agents):
            selected_for_agent = functions[index::agent_count]
            (directory / (agent + ".json")).write_text(json.dumps(selected_for_agent, indent=2) + "\n", newline="\n")
            (directory / (agent + ".prompt.txt")).write_text(prompt_for(owner, agent) + "\n", newline="\n")
        for prompt_path in directory.glob("*.prompt.txt"):
            if prompt_path.name.removesuffix(".prompt.txt") not in agents:
                prompt_path.unlink()
        data["agents"] = agents
        select_pal_batch.write_json(output, data)
        print(f"Using existing selection: {output}")
        return

    selected = select_pal_batch.select_functions(ROOT / "build/large56/pool.json", count)
    claimed = []
    try:
        for row in selected:
            if not dry_run:
                if not claims.claim(owner, row["name"]):
                    raise RuntimeError(f"{row['name']} is claimed by {claims.holder(row['name'])}")
                claimed.append(row["name"])
            row["status"] = "selected" if dry_run else "claimed"
            row["claim"] = None if dry_run else owner
    except Exception:
        for name in claimed:
            claims.release(owner, name)
        raise

    directory = batch_dir(owner)
    directory.mkdir(parents=True, exist_ok=True)
    agents = []
    for index in range(agent_count):
        agent = chr(ord("a") + index)
        functions = selected[index::agent_count]
        (directory / (agent + ".json")).write_text(json.dumps(functions, indent=2) + "\n", newline="\n")
        (directory / (agent + ".prompt.txt")).write_text(prompt_for(owner, agent) + "\n", newline="\n")
        agents.append(agent)
    document = {"owner": owner, "count": count, "bytes": sum(row["size"] for row in selected),
                "dry_run": dry_run, "agents": agents, "functions": selected}
    select_pal_batch.write_json(output, document)
    print(f"Prepared {count} functions for {agent_count} agents in {directory.relative_to(ROOT)}")


def launch(owner: str, provider: str | None, dry_run: bool) -> None:
    directory = batch_dir(owner)
    if not directory.exists():
        raise SystemExit("Run prepare first")
    workers = set(os.environ.get("PAL_BATCH_WORKERS", "").split(","))
    for prompt_path in sorted(directory.glob("*.prompt.txt")):
        agent = prompt_path.stem.removesuffix(".prompt")
        if workers != {""} and agent not in workers:
            continue
        prompt = prompt_path.read_text().strip()
        if "Never spawn subagents" not in prompt:
            prompt += " Never spawn subagents or additional packages; work through your assigned functions yourself."
        prompt += (" Resume existing scratch candidates, logs and documented variant counts for your assigned functions. "
                   "Do not repeat completed attempts or recompile unchanged candidates; continue from the best saved diff.")
        command = ["paseo", "run", "--no-wait", "--cwd", str(ROOT), "--mode", "auto", "--thinking", "high",
                   "--title", f"{owner}-{prompt_path.stem.removesuffix('.prompt')}"]
        if provider:
            command += ["--provider", provider]
        command += [prompt]
        if os.name == "nt":
            command = ["cmd.exe", "/c"] + command
        if dry_run:
            print(shlex.join(command))
            continue
        if shutil.which("paseo") is None:
            raise SystemExit("paseo CLI not found; use launch --dry-run and run the printed commands in your Paseo environment")
        subprocess.run(command, cwd=ROOT, check=True)


def manifest_entries(path: Path) -> list[dict]:
    data = json.loads(path.read_text())
    if isinstance(data, list):
        return data
    if isinstance(data.get("functions"), list):
        return data["functions"]
    return [{"name": name, **entry} for name, entry in data.items()]


def status(owner: str) -> None:
    accepted = reviewed = 0
    for path in sorted(batch_dir(owner).glob("*-matches.json")):
        entries = manifest_entries(path)
        reviewed += len(entries)
        accepted += sum(entry.get("verdict") == "MATCH" for entry in entries)
    print(json.dumps({"accepted": accepted, "reviewed": reviewed, "remaining": max(0, 50 - accepted)}, indent=2))


def collect(owner: str) -> None:
    functions = {}
    for path in sorted(batch_dir(owner).glob("*-matches.json")):
        for entry in manifest_entries(path):
            if entry.get("verdict") != "MATCH":
                continue
            source = entry["source"]
            name = entry.get("name") or entry.get("candidate")
            if not name or not name.startswith("func_"):
                name = "func_" + Path(source).stem
            if name in functions:
                raise SystemExit(f"Duplicate match: {name}")
            functions[name] = entry
    if len(functions) < 50:
        raise SystemExit(f"Only {len(functions)} matches; 50 required before integration")
    output = {"evidence": f"build/orchestrator/{owner}/evidence.json", "functions": dict(sorted(functions.items()))}
    select_pal_batch.write_json(batch_dir(owner) / "batch.json", output)
    print(f"Collected {len(functions)} matches in {batch_dir(owner).relative_to(ROOT) / 'batch.json'}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("command", choices=("prepare", "launch", "status", "collect"))
    parser.add_argument("--owner", default="paseo")
    parser.add_argument("--agents", type=int, default=3)
    parser.add_argument("--count", type=int, default=50)
    parser.add_argument("--provider")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()
    if not OWNER_RE.fullmatch(args.owner):
        parser.error("Invalid owner")
    if args.command == "prepare":
        if not 1 <= args.agents <= 3:
            parser.error("Use 1 to 3 agents")
        if args.count < 1:
            parser.error("Count must be positive")
        prepare(args.owner, args.count, args.agents, args.dry_run)
    elif args.command == "launch":
        launch(args.owner, args.provider, args.dry_run)
    elif args.command == "status":
        status(args.owner)
    else:
        collect(args.owner)


if __name__ == "__main__":
    main()
