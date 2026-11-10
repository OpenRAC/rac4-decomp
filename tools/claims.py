#!/usr/bin/env python3
"""
Shared claims, so several agents (Claude waves, a GPT agent, a person) can
match and land in one checkout without doing the same function twice or
overwriting each other's files (docs/agents/agent-workflow.md, "Several agents
at once").

  python3 tools/claims.py claim OWNER func_X [func_Y ...]   # take them
  python3 tools/claims.py release OWNER func_X [...]        # give them back
  python3 tools/claims.py who func_X [...]                  # who holds each
  python3 tools/claims.py list [OWNER]                      # all claims, or one owner's
  python3 tools/claims.py lock OWNER                        # take the landing lock
  python3 tools/claims.py unlock OWNER                      # release it

A claim is the file build/claims/<func>, holding its owner and the
time. Creating it is atomic, so of two agents claiming one function only
one gets it: `claim` prints `claimed` or `taken by <owner>` per function
and exits 1 if any was taken. Claim a function before working on it,
release it when you give up on it, and leave it claimed once it is
matched (it stays done). OWNER is any short name without spaces:
`gpt`, `claude`, a wave worker's `q7:k03`.

The landing lock (build/claims/LANDING/) serialises writes to src/:
take it before changing a source file, release it right after. A lock
older than LOCK_STALE seconds is taken as abandoned and broken. It is a
directory, not an flock, so it works the same on the host and inside the
build container, which share the checkout through a bind mount.

Standard library only: runs on the host and in the container.
"""
from __future__ import annotations
import os
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DIR = ROOT / "build/claims"
LOCK = DIR / "LANDING"
LOCK_STALE = 15 * 60


def path(func: str) -> Path:
    if not func.startswith("func_") or "/" in func:
        sys.exit(f"not a function name: {func}")
    return DIR / func


def holder(func: str) -> str | None:
    """The owner of FUNC's claim, or None."""
    try:
        return path(func).read_text().split()[0]
    except (FileNotFoundError, IndexError):
        return None


def claim(owner: str, func: str) -> bool:
    """Takes FUNC for OWNER. True if OWNER holds it now (a new claim or its
    own old one), False if someone else does."""
    DIR.mkdir(parents=True, exist_ok=True)
    try:
        with open(path(func), "x") as f:
            f.write(f"{owner} {time.strftime('%Y-%m-%dT%H:%M:%S')}\n")
        return True
    except FileExistsError:
        return holder(func) == owner


def release(owner: str, func: str) -> bool:
    if holder(func) != owner:
        return False
    path(func).unlink(missing_ok=True)
    return True


def claimed_by_others(owner: str) -> set[str]:
    """Functions someone other than OWNER (or anyone, for OWNER '') holds."""
    if not DIR.is_dir():
        return set()
    return {p.name for p in DIR.glob("func_*") if holder(p.name) != owner}


def lock(owner: str, wait: float = 1800) -> bool:
    """Takes the landing lock, waiting up to WAIT seconds. False when OWNER
    already held it (the caller must then leave it to that holder)."""
    DIR.mkdir(parents=True, exist_ok=True)
    deadline = time.time() + wait
    while True:
        try:
            LOCK.mkdir()
            (LOCK / "owner").write_text(f"{owner} {time.time():.0f}\n")
            return True
        except FileExistsError:
            try:
                who, since = (LOCK / "owner").read_text().split()
                if who == owner:
                    return False
                if time.time() - float(since) > LOCK_STALE:
                    unlock(who)                 # abandoned
                    continue
            except (FileNotFoundError, ValueError):
                pass                            # being created or removed: retry
            if time.time() > deadline:
                sys.exit(f"landing lock held by {(LOCK / 'owner').read_text().strip()}")
            time.sleep(0.2)


def unlock(owner: str) -> None:
    try:
        if (LOCK / "owner").read_text().split()[0] != owner:
            return
        (LOCK / "owner").unlink()
        LOCK.rmdir()
    except (FileNotFoundError, IndexError, OSError):
        pass


def main() -> None:
    args = sys.argv[1:]
    if not args:
        sys.exit(__doc__)
    cmd, rest = args[0], args[1:]
    if cmd in ("claim", "release") and len(rest) >= 2:
        owner, funcs = rest[0], rest[1:]
        failed = False
        for f in funcs:
            if cmd == "claim":
                ok = claim(owner, f)
                print(f"{f} claimed" if ok else f"{f} taken by {holder(f)}")
            else:
                ok = release(owner, f)
                print(f"{f} released" if ok else f"{f} not held by {owner}")
            failed |= not ok
        sys.exit(1 if failed else 0)
    if cmd == "who" and rest:
        for f in rest:
            print(f"{f} {holder(f) or '-'}")
        return
    if cmd == "list":
        for p in sorted(DIR.glob("func_*")) if DIR.is_dir() else []:
            line = p.read_text().strip()
            if not rest or line.split()[0] == rest[0]:
                print(f"{p.name} {line}")
        return
    if cmd == "lock" and len(rest) == 1:
        lock(rest[0])
        print("locked")
        return
    if cmd == "unlock" and len(rest) == 1:
        unlock(rest[0])
        print("unlocked")
        return
    sys.exit(__doc__)


if __name__ == "__main__":
    main()
