/* Not matching yet: PAL WIP; level_01 .text 0x0045F878, 256B. Not part of the build. */
/*
 * Actual288B/native256B: extra signed LB before each required LBU (three extra byte reads),
 * branch-owned store layout and repeated constant materialization remain.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 9d005f00f4473ce0a66bd197c0d83d9fee4352c32458a948781559944491ae86
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_0045F878 nonmatching/pal/l01_dreadzone_station/func_L01_0045F878.c --diff
 */
#include "common.h"

void func_L01_0045F878(void *object, f32 amount)
{
    u8 *cursor = object;
    void *target;
    u8 value;
    u8 value2;
    u8 value3;
    s32 index;

    target = *(void **)(cursor + 0x2EF0);
    *(u8 *)((u8 *)target + 0x23) = (u8)((u32)(s32)(amount * 115.0f) + 12U);
    target = *(void **)(cursor + 0x2EF0);
    value = *(u8 *)((u8 *)target + 0x23);
    if ((value & 0xFFU) >= 0x80U) {
        *(u8 *)((u8 *)target + 0x23) = 0x7F;
    } else if (value < 0xCU) {
        *(u8 *)((u8 *)target + 0x23) = 0xC;
    } else {
        *(u8 *)((u8 *)target + 0x23) = value;
    }

    index = 0;
    do {
        if (index != 3) {
            target = *(void **)(cursor + 0x22F0);
            if (target != 0) {
                *(u8 *)((u8 *)target + 0x23) = (u8)((u32)(s32)(amount * 115.0f) + 12U);
                target = *(void **)(cursor + 0x22F0);
                value2 = *(u8 *)((u8 *)target + 0x23);
                if ((value2 & 0xFFU) >= 0x80U) {
                    *(u8 *)((u8 *)target + 0x23) = 0x7F;
                } else if (value2 < 0xCU) {
                    *(u8 *)((u8 *)target + 0x23) = 0xC;
                } else {
                    *(u8 *)((u8 *)target + 0x23) = value2;
                }
            }
            target = *(void **)(cursor + 0x22F4);
            if (target != 0) {
                *(u8 *)((u8 *)target + 0x23) = (u8)((u32)(s32)(amount * 115.0f) + 12U);
                target = *(void **)(cursor + 0x22F4);
                value3 = *(u8 *)((u8 *)target + 0x23);
                if ((value3 & 0xFFU) >= 0x80U) {
                    *(u8 *)((u8 *)target + 0x23) = 0x7F;
                } else if (value3 < 0xCU) {
                    *(u8 *)((u8 *)target + 0x23) = 0xC;
                } else {
                    *(u8 *)((u8 *)target + 0x23) = value3;
                }
            }
        }
        index += 1;
        cursor += 0x50;
    } while (index < 6);
}
