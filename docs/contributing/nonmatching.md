# Near misses (`nonmatching/`)

A function that is close but not exact stays out of `src/`, so the build and
the progress report only ever hold matches. So does a function that matches only
with `volatile`, inline assembly, a `#define` alias or a hardcoded address
([`levers.md`](../agents/levers.md)). Its best attempt goes to
`nonmatching/`, which is never built.

## Where they live

The same areas as `src/`, one file per function, named after it:

| Function | File |
|---|---|
| core, network, resident level text | `nonmatching/core/`, `nonmatching/net/`, `nonmatching/game/` + `func_XXXXXXXX.c` |
| overlay code in two or more levels | `nonmatching/shared/func_LNN_XXXXXXXX.c` |
| overlay code in one level | `nonmatching/lNN_<level>/func_LNN_XXXXXXXX.c` |

C written against PAL under its PAL name (`src/pal/`) that stops matching goes
to `nonmatching/pal/<area>/func_XXXXXXXX.c`, its verdict from
`tools/check_func.py --version pal`. The tools do not count those yet.

Each file starts with a comment saying what still differs (and the command that
shows it, usually `tools/diff_func.py func_XXXXXXXX`), and gets a row in
[`nonmatching/README.md`](../../nonmatching/README.md).

## Working on one

Copy the draft into the right file in `src/` ([`workflow.md`](workflow.md)),
build and diff. Once it matches, delete it from `nonmatching/` and its row from
the README in the same commit.
