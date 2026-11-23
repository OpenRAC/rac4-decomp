/* Not matching yet: PAL WIP; count-copy, loop NOP and base differ. Not part of the build.
 * Primary: level_05 .text 0x004F4EB0, native 72 bytes. One default PAL trial produced
 * 64 bytes and one text. This preserves p01 input and actual CompiledSource unchanged.
 * Common missing-result return/two-JR topology recovered; native count transfer,
 * reachable loop NOP, pointer high-part register and shorter layout still differ.
 * Working ABI void *(s32): count is captured once; pointer cell is read only for
 * positive count, then entry key at +0x10 per iteration. Miss cursor advances by
 * defined low32 +0x20, including last miss. No new memory writes or helper calls.
 * Existing D_00222BF4[0] binds actual level05 PAL pointer cell 0x00222AF4; its US-style
 * numeric spelling is not the physical PAL address. Count D_PAL_00222AF8 binds
 * separate signed word 0x00222AF8. Both real HI16/LO16 pairs are valid; no data allocated.
 * No table extent, initializer, nonnull, nonalias or global termination guarantee.
 * L25 metadata carrier is not newly certified; no full source-bound carrier acceptance.
 * Historical missing timeout source/object remains UNKNOWN.
 * Reproduce without extra flags:
 * python3 tools/check_func.py --version pal func_L05_004F4EB0 nonmatching/pal/l05_dark_cathedral/func_L05_004F4EB0.c --diff
 */
#include "common.h"

extern u8 *D_00222BF4[];
extern s32 D_PAL_00222AF8;

void *func_L05_004F4EB0(s32 key)
{
    s32 count = D_PAL_00222AF8;
    s32 index = 0;

    if (count > 0) {
        u8 *cursor = D_00222BF4[0];
        do {
            s32 entryKey = *(s32 *)(cursor + 0x10);
            index += 1;
            if (entryKey == key) {
                return cursor;
            }
            cursor = (u8 *)((u32)cursor + 0x20U);
        } while (index < count);
    }
    return NULL;
}
