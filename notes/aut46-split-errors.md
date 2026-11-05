# Overlay split errors found in AUT-46

Two rows in `config/overlay_functions.tsv` start 8 bytes early and end 4 bytes
late. The first 8 retail bytes are the tail of the previous function
(`addiu $sp, $sp, 0x10` in its return's delay slot, then an alignment `nop`),
and the last 4 are a trailing alignment `nop`. No C function emits those, so
both stay at SIZE n−12 until the split is fixed.

| Row today | Should be | Body matches with | Best attempt |
|---|---|---|---|
| `func_L14_003EFAD0 0x003EFAD0 0xE0` | `0x003EFAD8`, `0xD8` | the C of `func_L01_0047E238`, renamed | `build/try/func_L14_003EFAD0/p2.c` (SIZE 212/224) |
| `func_L41_00417338 0x00417338 0xD8` | `0x00417340`, `0xCC` | sibling of `func_L01_00427C40` | `build/try/func_L41_00417338/p0.c` (SIZE 204/216) |

`config/us/functions.tsv` already has the right boundaries: it lists
`func_L41_00417340` (204 bytes) and gives L14:003EFAD0 to the 4-byte
`func_L00_00598110`.

After fixing the rows (and regenerating the overlay assembly), rerun both
candidates. For L14, map the six callees to their L14 addresses (0x3EFBB0,
0x3EFC88, 0x4E6F18, 0x3EFF30, 0x54F548, 0x544940) before landing:
`try_func` masks relocations.
