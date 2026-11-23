/* Not matching yet: PAL WIP; main .text 0x004F76C8, 264B. Not part of the build. */
/*
 * No saved-register frame; native SP-20,SQ s0/s1,LQ restores/SP+20 are absent, with call-clobbered
 * temporary allocation instead.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: dfbcd1a7e770f7d6c7775af74f1d4e2be079c365b18f21e7593574bae46e79d1
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_004F76C8 nonmatching/pal/game/func_004F76C8.c --diff
 */
#include "common.h"

/* Append the header and the observed sequence of packed coordinate words. */
void func_004F76C8(void **arg0, s32 arg1, s64 arg2, s32 arg3, s64 arg4,
                   s32 arg5, s64 arg6, s32 arg7, s32 arg_sp0, s32 arg_sp8)
{
    s32 temp_a3;
    s32 temp_a5;
    s32 temp_t4;
    s32 var_a4;
    s32 var_a5;
    s32 var_t6;
    u64 temp_a0_3;
    u64 temp_t7;
    u8 *temp_a0;
    u8 *temp_a0_2;
    u8 *temp_v1;
    u8 *temp_v1_2;
    s32 span_step;
    s32 coordinate_step;
    s32 coordinate_delta;

    temp_a5 = (s32)((u32)arg5 - (u32)arg1);
    temp_t4 = temp_a5 >> 9;
    span_step = temp_a5 / temp_t4;
    coordinate_delta = (s32)((u32)arg7 - (u32)arg3);
    temp_a0 = (u8 *)*arg0;
    var_t6 = arg1;
    *(u64 *)(temp_a0 + 0) =
        (u64)(s64)(temp_t4 | 0x8000) | ((u64)0x8800 << 47);
    temp_a0_2 = temp_a0 + 8;
    *arg0 = temp_a0_2;
    *(u64 *)(temp_a0 + 8) = 0x5353;
    *arg0 = temp_a0_2 + 8;
    coordinate_step = coordinate_delta / temp_t4;
    var_a4 = arg3;
    if (temp_t4 > 0) {
        temp_t7 = (u64)(s64)arg_sp8 << 32;
        var_a5 = temp_t4;
        do {
            temp_v1 = (u8 *)*arg0;
            temp_a0_3 = (u64)(s64)var_a4 | ((u64)arg4 << 16);
            var_a4 = (s32)((u32)var_a4 + (u32)coordinate_step);
            *(u64 *)(temp_v1 + 0) = temp_a0_3;
            temp_v1_2 = temp_v1 + 8;
            temp_a3 = (s32)((u32)var_t6 + (u32)span_step);
            *arg0 = temp_v1_2;
            *(u64 *)(temp_v1 + 8) =
                (u64)(s64)var_t6 | ((u64)arg2 << 16) | temp_t7;
            *arg0 = temp_v1_2 + 8;
            *(u64 *)(temp_v1_2 + 8) =
                (u64)(s64)var_a4 | ((u64)(s64)arg_sp0 << 16);
            *arg0 = temp_v1_2 + 16;
            *(u64 *)(temp_v1_2 + 16) =
                (u64)(s64)temp_a3 | ((u64)arg6 << 16) | temp_t7;
            var_t6 = temp_a3;
            var_a5 -= 1;
            *arg0 = temp_v1_2 + 24;
        } while (var_a5 != 0);
    }
}
