# AUT-39 matching attempts

- `func_00525EE0` (432 bytes): best candidate was SIZE 428 / 432. A second candidate using a runtime modulus was SIZE 416 / 432. The loop and register allocation still differ substantially.
- `func_004A0220` (976 bytes): best candidate was SIZE 916 / 976 after two candidates. The initializer's frame, call setup, and floating point setup remain different.
- `func_L01_00513F68` (224 bytes): best was SIZE 212 / 224 after two runs. The first candidate had the `count` and two array offsets wrong; correcting the layout remains to be explored, but the current wave budget is spent.
- `func_L01_00449C40` (160 bytes): both candidates were SIZE 144 / 160. The return/control flow and state byte offset differ.
- `func_L02_004BF8C8` (104 bytes): first candidate was SIZE 108 / 104. Callback argument ordering and store widths need correction; the current candidate wave budget is spent.
- `func_L01_00449E28` (152 bytes): first candidate failed in `ps2eeas_nops` because the source has one explicit `mtc1` use while assembly has none. No compiler output workaround attempted.
- `func_004EEDC8` (232 bytes): best candidate was BYTES 73 / 228. The output differs in floating point register allocation and operation ordering.
- `func_004EE978` (112 bytes): best candidate was BYTES 12 / 112. The source calculations match, but the compiler assigns different registers to the first three output lanes.
- `func_0049B568` (112-byte catalogue size): best try verdict was BYTES 8 / 108 after two identical attempts; the final store order still differs.
- `func_004EEA78` (80 bytes): best candidate was SIZE 64 / 80. The retail body has unusual stack pointer adjustments and argument setup.
- `func_004EEAC8` (96 bytes): best candidate was SIZE 80 / 96. Retail has unusual stack pointer adjustments before the body.

Other screened functions were skipped because their bodies use VU instructions that the C toolchain cannot express (`func_L01_0046B538`, `func_L01_004D96A0`, `func_L01_00550260`, and `func_L01_003CE868`).
