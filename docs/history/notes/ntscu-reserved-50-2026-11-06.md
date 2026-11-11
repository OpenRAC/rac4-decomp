# NTSC-U: 40 verified functions and allocator interface corrections

This batch adds **40 US matches / 1,836 bytes**, checked against owned SCUS_974.65 retail inputs. Twelve existing function interfaces/callers are corrected without changing their retail instructions. The four unresolved compiler-layout cases are excluded.

## Verification

The publication checkout is based on upstream `42e194af`. Every changed/new source unit was rebuilt through the pinned normal compiler/assembler routes. All 52 functions passed complete relocation-resolved byte equality with their objects unmodified. The 40 additions have 54 target checks; existing interface repairs are verified separately.

All unchanged source objects were reused only after source/header identity and object hashes were verified. Current-upstream additions were compiled before taking the baseline. GNU runtime/math objects were rebuilt. The full audits increase from 4,937 to 4,977 exact, retaining the same 158 legacy non-exact and 1,916 unlisted records. The 155 relocation mismatch and three unresolved records are identical to the fresh upstream baseline.

US map updates preserve every upstream row and add only the 40 new entries. US progress passes at 7,011 / 18,172 functions and 564,372 matched bytes. The two added inventory entries are separately identified stack-restoration remnants; alignment padding is excluded from the two proven initializer extents. Regression tests cover those boundary cases.

Thirty relevant compiler-route/profile and inventory tests pass. No game was launched and no runtime, gameplay or native-port proof is claimed.

**PAL limitation:** PAL retail inputs are unavailable locally. PAL files are preserved unchanged, and the PAL coverage check reports 40 missing rows for the new US definitions. The PR must remain draft until regional coverage is supplied and checked.

## Interface evidence and domain

The multiplayer overlay constructs an allocator, installs its table, and supplies it to network initialization. The recovered table uses a five-argument allocation callback returning a pointer and a two-argument release callback. `net_allocator.h` coordinates the types. Allocation results are preserved through the helpers; released pointers are forwarded; the dispatcher preserves its incremented unsigned counter as a signed target word. Newly merged callers of three batch functions have their ignored-return declarations aligned.

These interfaces use the recovered L00 allocator domain and the pinned 32-bit EABI. Pointer/word and unsigned/signed conversions are target-specific. Alternate allocator implementations and historical C++ declarations are not proved. Callback implementations added later must keep compatible types.

The circular-position operation requires positive capacity. Its source uses unsigned additions before signed remainder, preserving the pinned compiler's retail zero-divisor trap; no arbitrary-input or portable-language trap guarantee is claimed. The recovered eight-byte value copies require valid value objects that are identical or nonoverlapping; ordinary separate-word alignment requirements remain. The counter initializer requires distinct parent/entry/global storage and preserves the old counter and untouched field.

## New matches

| Function | Bytes |
|---|---:|
| `func_0012DA20` | 40 |
| `func_0012EC40` | 36 |
| `func_00154240` | 48 |
| `func_001559B0` | 48 |
| `func_001559E0` | 36 |
| `func_00155BC8` | 36 |
| `func_00156390` | 52 |
| `func_001563FC` | 52 |
| `func_001564EC` | 52 |
| `func_001565A0` | 44 |
| `func_001565CC` | 44 |
| `func_00156600` | 52 |
| `func_00156654` | 52 |
| `func_00156688` | 52 |
| `func_0015670C` | 52 |
| `func_00156784` | 52 |
| `func_01EA0BA0` | 48 |
| `func_01EA48A8` | 44 |
| `func_01EA55E8` | 48 |
| `func_01EA75C8` | 48 |
| `func_01EA8BA0` | 48 |
| `func_01EA8C38` | 48 |
| `func_01EB4E10` | 48 |
| `func_01EB4E68` | 48 |
| `func_01EB5A28` | 44 |
| `func_01EB5A58` | 44 |
| `func_01EBE188` | 44 |
| `func_01EC3430` | 48 |
| `func_01ED8608` | 40 |
| `func_01EDEB28` | 48 |
| `func_01EDF418` | 44 |
| `func_01EE38C4` | 40 |
| `func_01EEF25C` | 48 |
| `func_01EF0B14` | 40 |
| `func_01EF221C` | 40 |
| `func_01EF2C94` | 48 |
| `func_01EF2D88` | 48 |
| `func_01EF7CA8` | 40 |
| `func_01EFF2DC` | 48 |
| `func_01F02184` | 44 |

## Existing interface/caller corrections

- `func_0012D690`
- `func_0015DAC8`
- `func_01EE34A8`
- `func_01EE9D70`
- `func_01EEF8A4`
- `func_01EF0550`
- `func_01EF3748`
- `func_01EF58F4`
- `func_01F0AC68`
- `func_01F0C4CC`
- `func_L00_0077DF30`
- `func_L00_0077DF50`
