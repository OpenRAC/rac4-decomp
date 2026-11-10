## Contributing

The full procedure is in [`docs/contributing/workflow.md`](docs/contributing/workflow.md). In short:

1. Pick a function. `config/functions.tsv` and `config/overlay_functions.tsv`
   list every function with its size; small ones without data tables are a
   good start. Before decompiling, check whether it is library code with an
   open-source original (see Sources below).
2. Get a starting point with
   [m2c](https://github.com/matt-kempster/m2c):
   `venv/bin/python tools/ext/m2c/m2c.py -t mipsee-gcc-c asm/nonmatchings/.../func_XXXXXXXX.s`.
   For small functions, `tools/auto_structs.py` drafts and checks them in bulk.
3. Iterate. `venv/bin/python tools/try_func.py func_XXXXXXXX c1.c c2.c ...`
   compiles each candidate through the real pipeline and says `EXACT` or
   how many bytes are off, in seconds, without touching `src/`.
   [`docs/agents/levers.md`](docs/agents/levers.md) lists what makes functions match.
   For register or order near misses, [`docs/contributing/permuter.md`](docs/contributing/permuter.md).
   When it matches, put the C in its file under `src/`
   ([`docs/contributing/workflow.md`](docs/contributing/workflow.md) says which).
4. Build (`bash tools/build.sh`) and verify with
   `venv/bin/python tools/audit_matches.py`. A function that does
   not match yet goes to `nonmatching/`
   ([`docs/contributing/nonmatching.md`](docs/contributing/nonmatching.md)), never into `src/`.
5. Regenerate the progress reports (`tools/match_map.py --write` and
   `tools/progress.py --write`, each also with `--version pal`; see
   [`docs/contributing/workflow.md`](docs/contributing/workflow.md)) and commit them together with your
   change. CI fails if a report is out of date.

On macOS and Linux, prefix the build commands with `bash tools/docker/run.sh`.
m2c and asm-differ are used from local clones (not vendored):

```
git clone https://github.com/matt-kempster/m2c tools/ext/m2c
git clone https://github.com/simonlindholm/asm-differ tools/ext/asm-differ
```

## Build fidelity

The build uses retail's own compiler and reproduces only what SN's assembler
did to its output ([`docs/build/toolchain.md`](docs/build/toolchain.md)). So:

- never add a step that changes the compiler's output to make a function
  match; a function that only matches that way is not matched;
- options apply to whole source files (a `/* cflags: ... */` first line), never
  to one function: GCC 2.95 takes them per translation unit;
- if one function's nops differ from retail, refine the rule in
  `tools/ps2eeas_nops.py` with evidence from retail, not the C;
- matched C is plain C: no `volatile`, no inline assembly (`__asm__`, register
  pins, barriers), no `#define` that renames a global or an address, and no
  hardcoded addresses (a number cast to a pointer, hardware registers
  included). A function that only matches with
  one of them stays in `nonmatching/` ([`docs/agents/levers.md`](docs/agents/levers.md)).

The check is not link-time yet: `tools/audit_matches.py` masks the fields the
compiled object relocates (constants and offsets must equal retail), so a
function that calls or reads the wrong symbol can still pass.
`tools/audit_relocs.py` checks where the relocations of every exact function
point; it must report 0 mismatches.

## Sources

C here is reconstructed from the retail executable's own code. Allowed
as references:

- the retail binary (our assembly, m2c), and SDK library *binaries* the
  toolchain ships (`.a` archives: their code and symbol names, used the same
  way as the retail binary);
- open-source code under its own license: newlib, libgcc/GCC, and
  anything else whose license permits it, credited in
  `THIRD_PARTY_NOTICES.md`;
- other public decompilations of the engine family (rac1-decomp, the Up Your
  Arsenal decomp), credited, and public hardware documentation.

**Never** use Sony's SDK source, sample code or headers, or any leaked or
NDA material. Not as code, not as types or macros, not as a reference
to check a match against. Every name in `src/` is your own work
([`LEGAL.md`](LEGAL.md)).

## Commits and pull requests

- Small, focused commits: one function or one tool change.
- Run the build, the audit and `tools/progress.py --check` (and `--version pal --check`) before
  pushing.
- Commit messages: a short summary line, then an optional body. Add
  `Co-Authored-By:` for anyone (or any tool) who helped, and nothing else
  tool-specific: no session links.
- Never commit retail data: `asm/`, `assets/`, `baserom/`, `build/`, `venv/`,
  `toolchain/` and `private/` are ignored by git.
- CI (`.github/workflows/progress.yml`) checks and uploads both reports
  (`progress/report.json` for SCUS_974.65, `progress/pal/report.json` for SCES_532.85) to
  [ByteMatch](https://bytematch.dev/OpenRAC/rac-deadlocked-decomp).
  It cannot build the game, so the report is generated on your machine.

For LLM agents, [`docs/agents/agent-workflow.md`](docs/agents/agent-workflow.md) describes
how work is split between models.
