#!/usr/bin/env python3
"""
Plans, hands out and lands waves of worker agents (docs/agents/agent-workflow.md).
Ported from rac1-decomp, with the same commands and protocols
(docs/agents/queue.md, docs/agents/worker.md), on this repository's build and audit.

  venv/bin/python tools/wave.py plan NAME [func_X ...] [--queue] [--main]
                         [--count N] [--budget N] [--min-size N] [--max-size N]
                         [--near [--near-max F]] [--level NN]
      Picks functions (the ones named, or the next ones from the catalogue),
      starts a fresh BUDGET of try_func runs for each, writes each one's
      CONTEXT.md (its packet) and prints the workers' prompts: one per
      function, or with --queue one line for every queue worker.
  venv/bin/python tools/wave.py claim NAME ID [--count N]
      For a queue worker: claims the next N functions and prints each one's
      packet (calls, globals, assembly, an m2c draft, matched C to start from).
  venv/bin/python tools/wave.py status NAME
      One line per function: best verdict, runs used, best candidate.
  venv/bin/python tools/wave.py land NAME [--reject func_X ...] [--dry-run]
      Writes each EXACT into its file in src/ under the landing lock,
      re-checks it there with try_func, takes it back out if it is not exact,
      drops its near miss and releases the wave's unmatched claims. It does
      not build, regenerate the report or commit: the lead runs
      tools/build.sh, tools/audit_matches.py and tools/gen_progress_report.py.
  venv/bin/python tools/wave.py stage [func_X ...] [--max F]
      Shares near misses (docs/contributing/nonmatching.md): each function's closest
      logged attempt within --max (a fraction of its bytes; default 0.15)
      goes to nonmatching/<area>/func_X.c unless the staged one is as close.

Picking: by default the level overlays (`common` code first, the code more
levels share first, then smaller first); --main picks the executable's
functions instead, smallest first; --level NN keeps to functions of that
level. Functions already in src/, being tried (a runs.log), claimed by
another agent, libgcc/libm, or without assembly are skipped. --near picks
earlier attempts instead: a logged BYTES within --near-max of retail
(default 0.10) or a staged near miss, closest first; its packet starts from
that attempt (build/try/<func>/best.c and BEST_DIFF.txt).

Waves are recorded in build/waves/NAME.json; claims in build/claims/
(tools/claims.py). A run's chance of an EXACT falls with every run spent on
the same function (rac1-decomp, waves q6-q26), so the default budget is 6:
what is left of a function is a near wave's job.
"""
from __future__ import annotations
import argparse
import json
import re
import subprocess
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import claims as shared  # noqa: E402
import layout  # noqa: E402
import nonmatching  # noqa: E402

ROOT = layout.ROOT
TRY = ROOT / "build/try"
WAVES = ROOT / "build/waves"
PY = sys.executable
NEAR_MAX = 0.10
STAGE_MAX = 0.15
BLOCKED = re.compile(r"\b(cfc2|ctc2|qmfc2|qmtc2|vcallms|syscall|eret)\b|\.word|\$at\b")


# ---------------------------------------------------------------- picking
def logged_runs(work: Path) -> list[tuple[str, str]]:
    log = work / "runs.log"
    return [tuple(l.split(None, 1)) for l in log.read_text().splitlines() if " " in l] if log.exists() else []


def best_logged(work: Path) -> tuple[str, str]:
    """(verdict, candidate path) of the best run logged in WORK: the latest
    EXACT, else the closest BYTES, else the last verdict. The log is written
    by try_func, so nothing depends on what a worker reports."""
    runs = logged_runs(work)
    if not runs:
        return "(no run yet)", ""

    def rank(i_run):
        i, (_, verdict) = i_run
        if verdict.startswith("EXACT"):
            return (0, -i)
        m = nonmatching.miss(verdict)
        return (1, m) if m is not None else (2, -i)
    cand, verdict = min(enumerate(runs), key=rank)[1]
    path = work / cand
    return verdict.strip(), str(path.relative_to(ROOT)) if path.exists() else ""


def blocked(name: str) -> bool:
    asm = layout.asm_path(name)
    if asm is None:
        return True
    body = "\n".join(l.split("*/", 1)[-1] for l in asm.read_text(errors="replace").splitlines())
    ops = re.findall(r"^\s+([a-z][\w.]*)", body, re.M)
    if not ops or set(ops) == {"nop"}:
        return True                     # padding between functions, not code
    if "jr" not in ops and "j" not in ops:
        return True                     # a fragment: it never returns or tail-jumps
    return bool(BLOCKED.search(body))


def choose(args) -> list[str]:
    if args.funcs:
        for n in args.funcs:
            layout.info(n)
        return args.funcs
    cat = layout.catalogue()
    done = layout.defined()
    taken = shared.claimed_by_others("")
    pool = []
    for name, row in cat.items():
        overlay = bool(layout.OVERLAY_NAME.match(name))
        if overlay == args.main or row["area"] in ("libgcc", "libm"):
            continue
        if args.level is not None and not name.startswith(f"func_L{args.level:02d}_"):
            continue
        if name in done or name in taken or not args.min_size <= row["size"] <= args.max_size:
            continue
        pool.append(name)
    if args.near:
        staged = nonmatching.staged()
        near = []
        for name in pool:
            verdict, _ = best_logged(TRY / name)
            m = nonmatching.miss(verdict)
            if name in staged and m is None:
                m = nonmatching.miss(nonmatching.note(staged[name]))
                m = NEAR_MAX if m is None else m
            if m is not None and m <= args.near_max:
                near.append((m, name))
        return [n for _, n in sorted(near)][:args.count]
    pool = [n for n in pool if not (TRY / n / "runs.log").exists() and not blocked(n)]
    if args.main:
        pool.sort(key=lambda n: (cat[n]["size"], n))
    else:
        pool.sort(key=lambda n: (cat[n]["cls"] != "common", -len(cat[n]["levels"]), cat[n]["size"], n))
    return pool[:args.count]


# ---------------------------------------------------------------- packets
def declarations() -> dict[str, str]:
    """{symbol: its declaration} from src/ and include/: extern lines, and a
    prototype for every function defined in src/."""
    out = {}
    files = sorted((ROOT / "include").glob("*.h")) + sorted((ROOT / "src").rglob("*.c"))
    for p in files:
        if p.parts[-2] in ("libgcc", "libm"):
            continue
        for line in p.read_text(errors="replace").splitlines():
            if line.startswith("extern ") and line.rstrip().endswith(";"):
                for sym in re.findall(r"\b((?:func|D)_(?:L\d\d_)?[0-9A-F]{8}_?)\b", line):
                    # an old `D_x_[]` + `#define D_x (D_x_[0])` pair: show the plain form
                    out.setdefault(sym.rstrip("_"), re.sub(r"\b((?:func|D)_(?:L\d\d_)?[0-9A-F]{8})_\b", r"\1",
                                                           line.strip()))
            m = layout.DEF.match(line)
            if m:
                out[m.group(1)] = "extern " + line.split("{")[0].strip() + ";"
    return out


def clean_asm(path: Path) -> list[str]:
    return [re.sub(r"^\s*/\*[^*]*\*/\s*", "    ", l) for l in path.read_text(errors="replace").splitlines()
            if l.strip() and not l.startswith((".section", ".align", "nonmatching", "endlabel"))]


def m2c(name: str) -> str:
    m2c_py = ROOT / "tools/ext/m2c/m2c.py"
    asm = layout.asm_path(name)
    if not m2c_py.exists() or asm is None:
        return ""
    r = subprocess.run([PY, str(m2c_py), "-t", "mipsee-gcc-c", str(asm)], cwd=ROOT,
                       capture_output=True, text=True, timeout=60)
    return r.stdout.strip() if r.returncode == 0 else ""


def matched_neighbours(name: str, limit: int = 2, max_lines: int = 40) -> list[tuple[str, str]]:
    """Matched C of the same area, nearest in address: the usual spellings of
    the code around it."""
    row = layout.info(name)
    near = []
    for other, path in layout.defined().items():
        orow = layout.catalogue().get(other)
        if orow is None or orow["area"] != row["area"] or other == name:
            continue
        text = path.read_text(errors="replace")
        span = layout.definition_span(text, other)
        body = text.splitlines()[span[0]:span[1]]
        if len(body) <= max_lines:
            near.append((abs(orow["addr"] - row["addr"]), other, path, "\n".join(body)))
    near.sort()
    return [(f"{o} ({p.relative_to(ROOT)})", b) for _, o, p, b in near[:limit]]


def packet(name: str, budget: int, decls: dict[str, str] | None = None) -> str:
    row = layout.info(name)
    work = TRY / name
    decls = declarations() if decls is None else decls
    asm_file = layout.asm_path(name)
    asm = clean_asm(asm_file) if asm_file else ["(no assembly: run tools/setup_asm.sh / tools/gen_overlay_asm.py)"]
    body = "\n".join(asm)
    calls = sorted(set(re.findall(r"\bjal\s+(func_\w+)", body)) - {name})
    data = sorted(set(re.findall(r"%(?:hi|lo|gp_rel)\((D_\w+)\)", body)))
    gp = set(re.findall(r"%gp_rel\((D_\w+)\)", body))
    used = [int(m.group(1)) for c in work.glob("p*.c") if (m := re.fullmatch(r"p(\d+)\.c", c.name))]
    first = max(used) + 1 if used else 0
    where = layout.defined().get(name) or layout.src_path(name)
    levels = f", in {len(row['levels'])} level(s)" if row["levels"] else ""
    out = [f"===== {name}: {row['size']} bytes at 0x{row['addr']:08X}, {row['area']}{levels}. "
           f"Budget {budget} runs, work in build/try/{name}/, your first candidate is p{first}.c =====",
           f"- Lands in {where.relative_to(ROOT)}.",
           "", "## Calls"]
    out += [f"- {decls[c]}" if c in decls else f"- {c}: not declared anywhere yet" for c in calls] or ["- none"]
    out += ["", "## Globals"]
    for d in data:
        how = ("through $gp: a plain `extern` of up to 8 bytes" if d in gp else
               "through lui: declare it without a size, `extern T x[];` (levers.md)")
        out.append(f"- {decls[d]}   ({how})" if d in decls else f"- {d}: not declared anywhere yet ({how})")
    if not data:
        out.append("- none")
    out += ["", "## Assembly", *asm]
    best, diff = work / "best.c", work / "BEST_DIFF.txt"
    if best.exists():
        shown = diff.read_text(errors="replace").splitlines() if diff.exists() else ["(no diff written)"]
        out += ["", f"## Best earlier attempt: {shown[0]} (build/try/{name}/best.c)",
                "A near miss (queue.md, \"Near misses\"): start from this candidate and change as little "
                f"as you can. Your {budget} runs are a fresh budget.",
                best.read_text(errors="replace").rstrip(),
                "", "## What still differs (offset, ours | retail)", *(shown[1:] or ["- nothing listed"])]
    sketch = m2c(name)
    if sketch:
        out += ["", "## m2c draft (a sketch: types and structure need work)", sketch]
    for label, text in matched_neighbours(name):
        out += ["", f"## Matched C nearby: {label}", text]
    return "\n".join(out) + "\n"


# ---------------------------------------------------------------- waves
def load(name: str) -> dict:
    path = WAVES / f"{name}.json"
    if not path.exists():
        sys.exit(f"no wave {name} in {WAVES.relative_to(ROOT)}")
    return json.loads(path.read_text())


def claims_dir(wave: dict) -> Path:
    return WAVES / f"{wave['name']}.claims"


def keep_best(name: str) -> None:
    """For a near wave: the closest attempt, logged or staged, as best.c, and
    what still differs as BEST_DIFF.txt."""
    work = TRY / name
    verdict, cand = best_logged(work)
    staged = nonmatching.staged().get(name)
    if staged is not None:
        sm = nonmatching.miss(nonmatching.note(staged))
        lm = nonmatching.miss(verdict)
        if not cand or (sm is not None and (lm is None or sm < lm)):
            cand = str(staged.relative_to(ROOT))
    if not cand:
        return
    text = (ROOT / cand).read_text(errors="replace")
    if text.startswith("/* Not matching yet"):
        text = text.split("\n", 1)[1]
    (work / "best.c").write_text(text)
    r = subprocess.run([PY, "tools/try_func.py", name, str((work / "best.c").relative_to(ROOT)),
                        "--no-budget", "--diff"], cwd=ROOT, capture_output=True, text=True)
    lines = r.stdout.splitlines()
    head = next((l.split(":", 1)[1].split("(")[0].strip() for l in lines if l.startswith(name + ":")), "?")
    (work / "BEST_DIFF.txt").write_text("\n".join([head] + [l for l in lines if l.startswith("    0x")]) + "\n")


def plan(args) -> None:
    names = choose(args)
    if not names:
        sys.exit("nothing to plan")
    held = [f"{n} ({shared.holder(n)})" for n in names if shared.holder(n)]
    if held:
        print("still claimed, release before launching (claims.py release OWNER func):\n  " + "\n  ".join(held))
    stamp = time.strftime("%Y%m%d-%H%M%S")
    decls = declarations()
    for name in names:
        work = TRY / name
        work.mkdir(parents=True, exist_ok=True)
        for stale in ("best.c", "BEST_DIFF.txt"):
            (work / stale).unlink(missing_ok=True)
        if args.near:
            keep_best(name)
        if (work / "runs.log").exists():    # a fresh budget for this round
            (work / "runs.log").rename(work / f"runs.{stamp}.log")
        (work / "BUDGET").write_text(f"{args.budget}\n")
        (work / "CONTEXT.md").write_text(packet(name, args.budget, decls))
    WAVES.mkdir(parents=True, exist_ok=True)
    record = {"name": args.name, "budget": args.budget, "created": stamp, "started": time.time(),
              "functions": names, "queue": args.queue, "near": args.near}
    (WAVES / f"{args.name}.json").write_text(json.dumps(record, indent=2) + "\n")
    if args.queue:
        print(f"wave {args.name}: a queue of {len(names)} functions, budget {args.budget} runs each. "
              f"One prompt per worker (ID unique, N functions each, COUNT claimed at a time):\n\n"
              f"Read docs/agents/queue.md and follow it exactly. WAVE={args.name} ID=s01 N=6 COUNT=2")
        return
    print(f"wave {args.name}: {len(names)} workers, budget {args.budget} runs each\n")
    for name in names:
        if not shared.claim(f"{args.name}:{name[5:]}", name):
            print(f"{name}: taken by {shared.holder(name)}, skipped")
            continue
        print(f"Read docs/agents/worker.md and follow it exactly. FUNC={name} BUDGET={args.budget}")


def claim(args) -> None:
    """Hands the next unclaimed functions of a queue wave to worker ID and
    prints each one's packet. Creating the claim file is the lock."""
    wave = load(args.name)
    cdir = claims_dir(wave)
    cdir.mkdir(parents=True, exist_ok=True)
    # A worker that still holds a function it has not worked (no run logged)
    # gets that packet again instead of a new one.
    held = [p.name for p in sorted(cdir.iterdir())
            if p.read_text().strip() == args.id and not (TRY / p.name / "runs.log").exists()
            and not (TRY / p.name / "NOTES.md").exists()]
    if held:
        for name in held:
            print(packet(name, wave["budget"]))
        return
    got = []
    for name in wave["functions"]:
        if len(got) == args.count:
            break
        if (cdir / name).exists() or name in layout.defined() \
                or not shared.claim(f"{args.name}:{args.id}", name):
            continue
        (cdir / name).write_text(args.id + "\n")
        got.append(name)
    if not got:
        print("QUEUE EMPTY")
        return
    decls = declarations()
    for name in got:
        print(packet(name, wave["budget"], decls))


def status(args) -> None:
    wave = load(args.name)
    print(f"wave {wave['name']}: budget {wave['budget']}, {'queue' if wave['queue'] else 'one per worker'}")
    exact = tried = 0
    for name in wave["functions"]:
        verdict, cand = best_logged(TRY / name)
        runs = len(logged_runs(TRY / name))
        holder = shared.holder(name) or "-"
        exact += verdict.startswith("EXACT")
        tried += runs > 0
        landed = " (in src/)" if name in layout.defined() else ""
        print(f"  {name}  {verdict[:34]:34}  runs {runs:>2}/{wave['budget']}  {holder:14}  {cand}{landed}")
    print(f"{exact} exact, {tried - exact} tried, not exact, {len(wave['functions']) - tried} not tried yet")


BANNED = [
    (re.compile(r"\b__asm__\s*(?:__volatile__\s*)?\("), "inline assembly"),
    (re.compile(r"\b__asm__\s*\(\s*\"[^\"]*\"\s*:"), "inline assembly"),
    (re.compile(r"\basm\s*(volatile\s*)?\("), "inline assembly"),
    (re.compile(r"\bregister\b[^;]*\b(?:__asm__|asm)\s*\("), "a register pin"),
    (re.compile(r"__asm__\s*\(\s*\"[^\"]*[+\-][^\"]*\"\s*\)"), "an alias naming an expression"),
    (re.compile(r"\bvolatile\b"), "volatile"),
    (re.compile(r"^\s*#\s*define\s+\w+\s+[^\n]*\b(?:D|func)_(?:L\d\d_)?[0-9A-Fa-f]{6,8}", re.M), "a #define alias"),
    (re.compile(r"\(\s*[\w\s]*\*+\s*\)\s*\(?\s*0x[0-9A-Fa-f]{5,}|\(\s*\*\s*\)\s*\([^)]*\)\s*\)\s*0x[0-9A-Fa-f]{5,}"),
     "a hardcoded address"),
]


def banned(text: str) -> str | None:
    """Why a candidate may not land (queue.md, "Rules"), or None."""
    for pattern, why in BANNED:
        if pattern.search(text):
            return why
    return None


def land(args) -> None:
    import try_func
    wave = load(args.name)
    owner = f"land:{args.name}"
    landed, skipped = [], []
    for name in wave["functions"]:
        verdict, cand = best_logged(TRY / name)
        if not verdict.startswith("EXACT") or not cand or name in args.reject:
            continue
        if name in layout.defined():
            skipped.append((name, "already in src/"))
            continue
        text = (ROOT / cand).read_text(errors="replace")
        why = banned(text)
        if why:
            skipped.append((name, f"refused: {why}"))
            continue
        dst = layout.src_path(name)
        if dst.exists():
            skipped.append((name, f"{dst.relative_to(ROOT)} exists without it: land it by hand"))
            continue
        if args.dry_run:
            print(f"would land {name} -> {dst.relative_to(ROOT)}  ({cand})")
            continue
        took = shared.lock(owner)
        try:
            dst.parent.mkdir(parents=True, exist_ok=True)
            dst.write_text(re.sub(r"\n{3,}", "\n\n", try_func.source_text(name, text)).rstrip("\n") + "\n")
            layout.defined.cache_clear()
            check = WAVES / f"{args.name}-{name}.landed.c"
            span = layout.definition_span(dst.read_text(), name)
            check.write_text("\n".join(dst.read_text().splitlines()[span[0]:span[1]]) + "\n")
            r = subprocess.run([PY, "tools/try_func.py", name, str(check.relative_to(ROOT)), "--no-budget"],
                               cwd=ROOT, capture_output=True, text=True)
            (WAVES / f"{args.name}-{name}.verify.log").write_text(r.stdout + r.stderr)
            if "EXACT" not in r.stdout:
                dst.unlink()
                layout.defined.cache_clear()
                skipped.append((name, "not exact re-checked in its file: taken back out"))
                continue
        finally:
            if took:
                shared.unlock(owner)
        nonmatching.drop(name)
        landed.append(name)
        print(f"landed {name} -> {dst.relative_to(ROOT)}", flush=True)
    if args.dry_run:
        return
    nonmatching.readme()
    cdir = claims_dir(wave)
    freed = [n for n in wave["functions"]
             if n not in landed and (cdir / n).exists()
             and shared.release(f"{args.name}:{(cdir / n).read_text().strip()}", n)]
    for name, why in skipped:
        print(f"skipped {name}: {why}")
    print(f"{len(landed)} landed, {len(skipped)} skipped; {len(freed)} unmatched claims released")
    if landed:
        print("Next: bash tools/docker/run.sh bash tools/build.sh, venv/bin/python tools/audit_matches.py, "
              "python3 tools/gen_progress_report.py; check the calls and globals of each landed function "
              "by eye (the compare masks them).")


def stage(args) -> None:
    names = args.funcs or (sorted(p.name for p in TRY.iterdir() if p.is_dir()) if TRY.is_dir() else [])
    n = 0
    for name in names:
        if name not in layout.catalogue() or name in layout.defined():
            continue
        verdict, cand = best_logged(TRY / name)
        m = nonmatching.miss(verdict)
        if m is None or m > args.max or not cand:
            continue
        if nonmatching.stage(name, ROOT / cand, verdict):
            print(f"staged {name}: {verdict}")
            n += 1
    nonmatching.readme()
    print(f"{n} staged")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    commands = parser.add_subparsers(dest="command", required=True)
    p = commands.add_parser("plan")
    p.add_argument("name")
    p.add_argument("funcs", nargs="*")
    p.add_argument("--queue", action="store_true")
    p.add_argument("--main", action="store_true")
    p.add_argument("--level", type=int)
    p.add_argument("--count", type=int, default=10)
    p.add_argument("--budget", type=int, default=6)
    p.add_argument("--min-size", type=int, default=0)
    p.add_argument("--max-size", type=int, default=400)
    p.add_argument("--near", action="store_true")
    p.add_argument("--near-max", type=float, default=NEAR_MAX)
    c = commands.add_parser("claim")
    c.add_argument("name")
    c.add_argument("id")
    c.add_argument("--count", type=int, default=2)
    commands.add_parser("status").add_argument("name")
    l = commands.add_parser("land")
    l.add_argument("name")
    l.add_argument("--reject", nargs="*", default=[])
    l.add_argument("--dry-run", action="store_true")
    st = commands.add_parser("stage")
    st.add_argument("funcs", nargs="*")
    st.add_argument("--max", type=float, default=STAGE_MAX)
    args = parser.parse_args()
    {"plan": plan, "claim": claim, "status": status, "land": land, "stage": stage}[args.command](args)


if __name__ == "__main__":
    main()
