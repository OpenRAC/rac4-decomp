/* Not matching yet: PAL WIP; main net.text 0x01EB2C50, 92B. Not part of the build. */
/*
 * Both actual prior advancingloop objects128B versus complete native92B; no fresh compile or fresh
 * verdict claimed.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 221cb93686483a5d75e6ecb94d541de46c16a038a9857695f5619bcaf512db3a
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EB2C50 nonmatching/pal/net/func_01EB2C50.c --diff
 */
#include "common.h"

void func_01EB2C50(u8 *dst, u8 *src, s32 count)
{
    do {
        u64 value = *(u64 *)src;
        dst[0] = (u8)value;
        value >>= 8;
        dst[1] = (u8)value;
        value >>= 8;
        dst[2] = (u8)value;
        value >>= 8;
        dst[3] = (u8)value;
        value >>= 8;
        dst[4] = (u8)value;
        value >>= 8;
        dst[5] = (u8)value;
        value >>= 8;
        dst[6] = (u8)value;
        value >>= 8;
        dst[7] = (u8)value;
        count -= 8;
        src += 8;
        dst += 8;
    } while (count > 0);
}
