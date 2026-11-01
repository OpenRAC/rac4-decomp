# One-function NTSC-U follow-up, 2026-10-31

Starting revision: `d91a9c46`. Fetched origin/main remained `74961298`;
the clean local branch was two commits ahead. Refreshed and inspected all
six open PRs (#48 through #53), including their actual diffs, and checked
source, US/PAL maps, claims and existing attempts before selection.

Matched **`func_001221D8`**, 108 bytes, in `src/core/001221D8.c`.
It rounds a trailing decimal digit and propagates carry through preceding
`'9'` bytes. It has no calls, globals or relocations. Its normalized US
code is unique among the resident functions checked, and no existing map
row owned its place. No PR overlap was found. PAL inventory has the same
address/size; PAL instruction bytes remain unavailable.

The Terra Medium worker used four of six allowed candidate runs; p3.c
matched. Primary review verified all 108 bytes against retail without
masking, then integrated under the landing lock and rebuilt the source
through the existing local launcher. That rebuild also matched exactly.
The function can access preceding storage for a length-one rounding input,
as retail does; its caller must provide valid storage on that path. No
undefined-behavior or instruction-injection trick was used to obtain the match.

The legacy byte audit adds exactly this function (3,502 to 3,503 exact),
retaining the same three non-exact functions and 761 unlisted functions.
Full relocation records remain identical: 80 existing discrepancies and
three unresolved targets. No clean whole-tree audit is claimed.

Only the new row from the official US map generator was adopted; all
pre-existing map rows and their ordering were preserved. US progress and
the README table were regenerated: 4,156 functions, 322,648 matched bytes.
US coverage/progress and whitespace checks pass. PAL files are unchanged;
its missing mapping rows now include this source alongside the previous
four, and the PAL coverage guard remains failing without PAL inputs.

Candidates, notes, baseline snapshots, PR exclusions, independent proof
and audit logs remain in ignored `build/try/func_001221D8/` and
`build/batches/codex-20261031-single-02/`. The matched claim is retained.
Only this function was attempted. No tools, toolchains or previous matches
were changed. No squash, push, PR or game launch was performed.
