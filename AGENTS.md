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

## Pull requests: batch your matches

Maintainers merge pull requests and refresh the reports by hand, once per round, so every extra
pull request costs real time and adds conflicts in the generated files. For match work, every
contributor and every agent follows these rules:

- **One open match pull request per contributor at a time.** While you work, keep adding commits to
  it instead of opening a new pull request for each small set of matches. Open a separate one only
  for unrelated work (a tool or docs change) or an urgent fix to a broken build.
- **Clustered commits.** Make one commit per cluster of related matches: a family of twins across
  levels, one source file, one level or one subsystem. Aim for **10 or more functions per commit**,
  and gather small leftovers into one commit rather than committing them one at a time. A commit
  with a single function is right only when the function is large (1 KB or more) or needed a
  structural change, such as a file cut or a header change, that deserves its own review.
- **Prioritise clusters of 10+.** When choosing what to match next, prefer families and files
  where 10 or more functions can land together over scattered one-offs.
- **Ready for review at about 30 functions or more.** A smaller pull request is fine when it
  finishes a family or a file, or fixes something.
- **Generated files once, in the last commit.** Regenerate the reports and maps in the pull
  request's final commit, not in every commit; they are where pull requests conflict most.
- Every commit still leaves the build and the checks green. The description lists the functions,
  grouped by commit.

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
