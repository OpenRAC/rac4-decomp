/* Not matching yet: PAL WIP; main .text 0x004644F8, 184B. Not part of the build. */
/*
 * Actual B8 store precedes A4 despite source A4-before-B8 order. This store-order mismatch is
 * retained explicitly.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 004886c93336a7ac91effbcfb240b706da4c4fb13c7edc6ee715e0e281eddd83
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_004644F8 nonmatching/pal/game/func_004644F8.c --diff
 */
#include "common.h"

extern s32 D_00237100[];
extern u8 D_001C20C0[];
void func_001634A8(s32 repeat);
u32 func_00163808(s32, u32, u32, u32, u32, s32, s32);

s32 func_004644F8(void)
{
    u32 *resident = (u32 *)D_00237100;
    u8 *table = D_001C20C0;
    u8 *record;
    s32 count;
    u32 companion;
    s32 result = 0;

    resident[0xB8 / 4] = 0;
    record = table + 0x8000 + resident[0x70 / 4] * 0x14CU;
    count = *(s32 *)(record + 0x5ACC);
    companion = *(u32 *)(record + 0x5AC8);
    if (count > 0) {
        u32 remaining = resident[0xA4 / 4];
        u32 common = *(u32 *)(table + 0xDABC);
        u32 next = remaining - ((u32)count << 11);

        companion += common;
        resident[0xA4 / 4] = next;
        resident[0xB8 / 4] = next;
        func_001634A8(1);
        func_00163808(0, resident[0xB8 / 4], companion, (u32)count,
                      (u32)(table + 0xDAB8), 0, 0);
        result = 1;
    }
    return result;
}
