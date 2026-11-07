# Agent workflow

How matching runs when models do it: one lead model plans waves, launches
cheap workers, reviews what they match and lands it, and a strict tool
decides what counts as a match. The goal is the most matched bytes per
token. The setup, the tools and the model tiers come from rac1-decomp's
[agent workflow](https://github.com/OpenRAC/rac1-decomp/blob/main/docs/AGENT_WORKFLOW.md),
where every setting was measured.

[WORKFLOW.md](WORKFLOW.md) covers the build and the manual loop,
[QUEUE.md](QUEUE.md) is the queue workers' protocol, [WORKER.md](WORKER.md)
the single worker's, [OVERLAYS.md](OVERLAYS.md) the level code most waves
draw from.

## At a glance

| Role | Model | Does |
|---|---|---|
| Lead | Opus 5.5 | plans, launches, refills, reviews, lands; runs the build, the audit and the report; matches nothing itself |
| Tools first | no model | `tools/auto_structs.py` on the smallest functions not in `src/` yet: whatever a script can close never reaches a model |
| Swarm worker | Haiku 5.5 (`model: haiku`), 8 to 10 at once | small functions, about 400 bytes and under; a first pass that matches what it can and leaves notes and a near miss for the rest |
| Escalation worker | Opus 5.5 (`model: opus`), 2 to 4 at once | what the swarm left close, and functions of 1 KB or more, one per agent, 20 to 30 runs |
| (rarely) | Sonnet 5.5 | only library code with a reference source; rac1 measured it no better than Haiku on game code |

Work flows up: tools, then Haiku on the small functions, then Opus on
Haiku's near misses and on the long functions, each starting from the
notes and best candidate of the tier below. A worker stops at its budget
and hands its attempt up a tier; it never keeps grinding.

The worker agent is `.claude/agents/match-worker.md`. A queue worker's whole
prompt is one line:

```
Read docs/QUEUE.md and follow it exactly. WAVE=q1 ID=s01 N=6 COUNT=2
```

`WAVE` is the wave's name, `ID` the worker's id (never reused within a
wave), `N` how many functions it handles, `COUNT` how many it claims at a
time.

## The pieces

| Tool | Does |
|---|---|
| `tools/wave.py plan` | picks functions, gives each a BUDGET of runs and a packet (`build/try/<func>/CONTEXT.md`), records the wave in `build/waves/` and prints the prompts |
| `tools/wave.py claim` | hands a queue worker its next functions and prints their packets |
| `tools/try_func.py` | compiles one candidate through the real pipeline in `build/try/<func>/` and compares it with retail; logs every run, enforces the budget |
| `tools/wave.py status` | the best logged verdict of each function |
| `tools/wave.py land` | writes each EXACT into `src/` under the landing lock and re-checks it there |
| `tools/wave.py stage` | puts what came close into `nonmatching/` (`tools/nonmatching.py`) |
| `tools/claims.py` | claims and the landing lock, shared by waves and by any other agent |
| `tools/layout.py` | where each function's catalogue row, retail bytes, assembly and files are |

Run them with `venv/bin/python` on the host: try_func compares against the
overlay ELFs, which live outside the repository, and starts the container
only to compile.

## The lead's loop

1. Tools first: `tools/auto_structs.py prepare`, compile, `check`, `adopt`
   ([WORKFLOW.md](WORKFLOW.md#automatic-drafts-toolsauto_structspy)).
2. Plan a wave:
   `venv/bin/python tools/wave.py plan q1 --queue --count 24 --max-size 400`
   (overlay code: `common` code first, the code most levels share first,
   smaller first; `--main` for the executable, `--level NN` for one level).
   Padding, fragments and functions with VU0 or `$at` code are left out.
3. Launch 8 to 10 Haiku workers with the printed line, each with its own
   `ID`. Refill as they end; `wave.py status q1` shows where the wave is.
4. Review every EXACT before landing: open the candidate and check its
   calls and globals against the assembly. try_func masks them, so a
   wrong callee or global still says EXACT. Reject what is wrong with
   `--reject func_X`.
5. Land: `wave.py land q1`. Then `tools/build.sh`,
   `tools/audit_matches.py` (the count goes up by the landed functions),
   `tools/audit_relocs.py` (0 mismatches: it catches the wrong callees and
   globals the review missed) and `tools/match_map.py --write` plus
   `tools/progress.py --write` (each also `--version pal`), once, after
   every worker has finished.
6. Stage near misses: `wave.py stage`. The next tier starts from them:
   `wave.py plan q2 --near` gives each one's best attempt and what still
   differs; for the long ones, plan the named functions with
   `--budget 30` and launch Opus workers with WORKER.md.

## Several agents at once

Before matching across separate checkouts, contributors reserve a manageable
scope in the [function reservation issue](https://github.com/OpenRAC/rac4-decomp/issues/112).
Follow the repository-level
[`AGENTS.md`](../AGENTS.md): check for overlapping active reservations, edit
only your own coordination comment, and keep each reservation to functions
you intend to attempt next. If there is no reservation issue, create one
before starting matching work. GitHub reservations coordinate contributors;
they do not replace the repository as the source of truth for completed work.

Within one shared checkout, `tools/claims.py` remains the atomic lock that
prevents two workers from taking the same function. Use both layers when
contributors work in separate checkouts but share agents or worktrees.

Several agents can work in one checkout (Claude waves, another model, a
person) through `tools/claims.py`:

```
python3 tools/claims.py claim gpt func_L01_00631CB8     # "claimed", or "taken by <owner>" (exit 1)
python3 tools/claims.py release gpt func_L01_00631CB8   # giving up on it
python3 tools/claims.py who func_L01_00631CB8
python3 tools/claims.py list [OWNER]
python3 tools/claims.py lock gpt      # before writing any file in src/
python3 tools/claims.py unlock gpt    # right after
```

- **Claim before working on a function.** A claim is the file
  `build/claims/<func>`; creating it is atomic, so only one agent gets a
  function. Release it when you give up on it; leave it once matched.
  `wave.py plan` and `claim` use the same claims: waves never take another
  agent's function, and `land` frees a wave's unmatched ones.
- **Take the landing lock around every write to `src/`.** `wave.py land`
  takes it itself; an agent that edits source files by hand runs `lock`
  and `unlock` around the edit. A lock older than 15 minutes counts as
  abandoned.
- **One owner for the report and the commits.** Only the lead regenerates
  `progress/report.json`, once, when every agent has finished; the user
  decides what is committed. Agents leave their matches uncommitted.
- Matching itself never collides: try_func works in `build/try/<func>/`,
  and `tools/cc.sh` names its temporary files after the whole output path.

## Rules every brief carries

They are in QUEUE.md, so the one-line prompt is enough:

- plain C: no register pins, inline assembly, barriers, `volatile`,
  `#define` aliases or hardcoded addresses;
- write only in `build/try/<func>/`, never delete, never commit, no
  sub-agents, no web;
- compile only through try_func;
- never Sony SDK source, samples or headers, or leaked material
  ([LEGAL.md](../LEGAL.md));
- names by address only;
- the build is fixed: no new step that edits compiler output, flags only
  per file ([CONTRIBUTING.md](../CONTRIBUTING.md#build-fidelity)).

## Running it on a smaller plan

With room for 2 or 3 workers the loop is unchanged: plan a wave of 16 to
24 functions, keep 2 or 3 workers busy, refill as they end, land once.
The wave takes longer; the cost per match is the same.
