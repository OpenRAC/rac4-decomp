/* Not matching yet: PAL WIP; main .text 0x004E0E28, 92B. Not part of the build. */
/*
 * Actual object omits the mandatory intermediate halfword store although source assigns it.
 * Missing effect remains unresolved.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: c5610aea6a3ce7364c1f0fe62cc8b8090ced73181d26fecb7a9bd609c6cdc8b0
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_004E0E28 nonmatching/pal/game/func_004E0E28.c --diff
 */
#include "common.h"

extern u16 D_0021FD74;
extern u8 D_001D2280[];

s16 func_004E0E28(s32 id)
{
    s16 result = -1;
    u16 old = D_0021FD74;
    u16 next;

    if (id != -1) {
        result = (s16)((u32)id | ((u32)old << 6));
        next = (u16)(old + 1u);
        D_0021FD74 = next;
        *(u16 *)(D_001D2280 + (((u32)id << 7) + 0x318u)) = old;
        D_0021FD74 = (u16)((u32)next % 1023u);
    }
    return result;
}
