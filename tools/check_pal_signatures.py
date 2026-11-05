#!/usr/bin/env python3
"""Check PAL function prototypes against config/pal/signatures.tsv."""
from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PROTOTYPE = re.compile(
    r"^[ \t]*(?:extern[ \t]+)?"
    r"((?!typedef\b|static\b|return\b)[A-Za-z_][A-Za-z0-9_ \t*]*\bfunc_[0-9A-F]{8}"
    r"\s*\([^;{}]*\)[^;{}]*);",
    re.MULTILINE,
)
COMMENTS = re.compile(r"/\*.*?\*/|//[^\n]*", re.DOTALL)
DECLARATION = re.compile(r"^(.*?)\b(func_[0-9A-F]{8})\s*\((.*)\)$", re.DOTALL)


def normalize(text: str) -> str:
    text = " ".join(text.split())
    text = re.sub(r"\b(?:unsigned\s+)?int\b", lambda match: "u32" if "unsigned" in match.group(0) else "s32", text)
    text = re.sub(r"\bconst\s+", "", text)
    text = re.sub(r"\s*\*\s*", "*", text)
    text = re.sub(r"\s*,\s*", ",", text)
    return text


def split_declarations(text: str):
    start = depth = 0
    for index, char in enumerate(text):
        if char == "(":
            depth += 1
        elif char == ")":
            depth -= 1
        elif char == "," and depth == 0:
            yield text[start:index]
            start = index + 1
    yield text[start:]


def normalize_parameters(text: str) -> str:
    parameters = []
    type_words = {"void", "char", "short", "int", "long", "signed", "unsigned",
                  "s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64"}
    for parameter in split_declarations(text):
        parameter = parameter.strip()
        named = re.fullmatch(r"(.+[\s*])([A-Za-z_]\w*)", parameter)
        if named and named[2] not in type_words:
            parameter = named[1].rstrip()
        parameters.append(normalize(parameter))
    return ",".join(parameters)


def signatures():
    for line in (ROOT / "config/pal/signatures.tsv").read_text().splitlines():
        if not line or line.startswith("#"):
            continue
        name, address, result, parameters, stack, status, evidence = line.split("\t")
        yield name, address, result, parameters, stack, status, evidence


def parse_declarations(text: str):
    # A file-scope function declaration has external linkage without `extern`
    # too. Comments must not contribute apparent declarations.
    text = COMMENTS.sub(" ", text)
    for statement in PROTOTYPE.findall(text):
        inherited_result = None
        for part in split_declarations(statement):
            match = DECLARATION.fullmatch(part.strip())
            if not match:
                continue
            result, name, parameters = match.groups()
            result = result.strip() or inherited_result
            inherited_result = inherited_result or result
            yield name, normalize(result), normalize_parameters(parameters)


def declarations():
    for path in (ROOT / "src/pal/game").rglob("*.c"):
        text = path.read_text(errors="replace")
        for name, result, parameters in parse_declarations(text):
            yield path, name, result, parameters


def main() -> int:
    requested = set(sys.argv[1:])
    entries = [entry for entry in signatures() if not requested or entry[0] in requested]
    if requested and not entries:
        raise SystemExit("No signature entry for " + ", ".join(sorted(requested)))
    found = {}
    for path, name, result, parameters in declarations():
        found.setdefault(name, []).append((path, result, parameters))

    problems = 0
    for name, address, result, parameters, stack, status, evidence in entries:
        if status not in ("confirmed", "confirmed_contract", "confirmed_abi"):
            print(f"{status.upper()}: {name}: {evidence}")
            continue
        expected = (normalize(result), normalize(parameters))
        mismatches = []
        for path, actual_result, actual_parameters in found.get(name, []):
            actual = (actual_result, actual_parameters)
            if actual != expected:
                mismatches.append((path, actual))
        if mismatches:
            for path, actual in mismatches:
                problems += 1
                print(f"MISMATCH: {name} in {path.relative_to(ROOT)}")
                print(f"  expected: {expected[0]}({expected[1]})")
                print(f"  actual:   {actual[0]}({actual[1]})")
                print(f"  evidence: {evidence}")
        else:
            print(f"CONFIRMED: {name}: {expected[0]}({expected[1]}); stack: {stack}")
    if problems:
        print(f"{problems} declaration mismatch(es)")
        return 1
    print(f"Checked {len(entries)} signature entries; no confirmed declaration mismatches")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
