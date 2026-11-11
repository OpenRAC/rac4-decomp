# Instructions for agents

Read this file before changing anything, then read `README.md`,
`CONTRIBUTING.md`, `docs/contributing/workflow.md` and `docs/agents/agent-workflow.md`. For a
function match, follow `docs/agents/queue.md` or `docs/agents/worker.md` as applicable.

## Coordinate function work

Before starting or assigning function matching, check the [function
reservation issue](https://github.com/OpenRAC/rac4-decomp/issues/112) for
active reservations. Use one coordination issue with one comment per
contributor, edited in place. Read the other active comments
before choosing functions; reserve only the work you intend to attempt next,
and update your comment when you finish, drop or replace a scope. Do not edit
another contributor's comment. Count distinct unfinished functions once,
regardless of how many levels carry them, and keep a reservation manageable
(at most 500 unfinished functions across a contributor's branches, worktrees
and agents).

If no reservation issue exists yet, create one before starting matching work.
The issue is a coordination noticeboard, not the source of truth for matches:
the repository and merged code remain authoritative. A reservation covers
functions, not unrelated work elsewhere in the same source file. Coordinate
file edits when separate reservations touch the same source file.

In a shared checkout, also use the local atomic claims in `tools/claims.py`:

```sh
python3 tools/claims.py claim OWNER func_L01_00631CB8
python3 tools/claims.py who func_L01_00631CB8
python3 tools/claims.py list
python3 tools/claims.py release OWNER func_L01_00631CB8
```

Claim before working. The file in `build/claims/` prevents concurrent workers
in this checkout from taking the same function; the GitHub reservation avoids
overlap between separate checkouts. Release a claim when giving up. Leave a
matched function claimed until it is integrated. Before writing to `src/`, use
the landing lock (`tools/claims.py lock OWNER` / `unlock OWNER`); `wave.py land`
does this itself. Wave planning and queue workers already share these claims.

## Matching workflow

- Use `config/functions.tsv` and `config/overlay_functions.tsv` to choose
  distinct functions and see their sizes and placements. Check
  `nonmatching/README.md` and retained notes before retrying prior work.
- Use `tools/try_func.py` for candidate checks. Only exact results accepted by
  the repository's audit and build belong in `src/`; near misses go in
  `nonmatching/` according to `docs/contributing/nonmatching.md`.
- Follow the sourcing and build-fidelity rules in `CONTRIBUTING.md`. Never use
  Sony SDK source, samples or headers, or leaked material. Do not change the
  compiler output with per-function tricks.
- Do not commit game data, disassembly, build output or proprietary tools.
  Follow the report-generation procedure in `docs/contributing/workflow.md`.

For wave workers, the packet protocol in `docs/agents/queue.md` is the complete
function-level instruction set. Do not work on a function outside the assigned
packet or reservation.
