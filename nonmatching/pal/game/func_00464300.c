/* Not matching yet: PAL WIP; main .text 0x00464300, 180B. Not part of the build. */
/*
 * Extra retained table base s3 across calls, native rematerializes final table pointer.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 627e3e53b4ffce0339bd2028de0eb783ef243525f0d8e2778ab84d7083108aaf
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00464300 nonmatching/pal/game/func_00464300.c --diff
 */
#include "common.h"

extern s32 D_00237100[];
extern s32 D_001C20C0[];
void func_001634A8(s32 repeat);
u32 func_00163808(s32, u32, u32, u32, u32, s32, s32);

s32 func_00464300(void)
{
    u32 *resident = (u32 *)D_00237100;
    u8 *table = (u8 *)D_001C20C0;
    u8 *record;
    s32 count;
    u32 companion;
    s32 result = 0;

    resident[0xBC / 4] = 0;
    record = table + 0x8000 + resident[0x70 / 4] * 0x14CU;
    count = *(s32 *)(record + 0x5AF4);
    companion = *(u32 *)(record + 0x5AF0);
    if (count > 0) {
        u32 remaining = resident[0xA4 / 4];
        u32 common = *(u32 *)(table + 0xDABC);

        companion += common;
        resident[0xBC / 4] = remaining - ((u32)count << 11);
        func_001634A8(1);
        func_00163808(0, resident[0xBC / 4], companion, (u32)count,
                      (u32)(table + 0xDAB8), 0, 0);
        result = 1;
    }
    return result;
}
