/* Not matching yet: PAL WIP; level_01 .text 0x004F5108, 180B. Not part of the build. */
/*
 *  0x0028 addu $v0, $v0, $s1 | addu $v0, $s1, $v0 0x0040 b . + 4 + (0x16 << 2) | b . + 4 + (0x17
 * << 2) 0x004C addu $v0, $v0, $s1 | addu $v0, $s1, $v0 0x0050 lwc1 $f1, 0x2B4($v0) | lwc1 $f2,
 * 0x2B4($v0) 0x0054 c.lt.s $f0, $f1 | c.lt.s $f0, $f2 0x005C bc1f . + 4 + (0xE << 2) | bc1f . + 4
 * + (0xF << 2) 0x006C mtc1 $at, $f0 | mtc1 $at, $f1 0x0074 add.s $f0, $f1, $f0 | addiu $a0, $zero,
 * 0x1 0x0078 lwc1 $f1, 0x278($v0) | add.s
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 487a46226e56e6ff417758e4ca77d976bfa788d14232bb601e2f8cb3b0fe57e0
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_004F5108 nonmatching/pal/shared/func_L01_004F5108.c --diff
 */
#include "common.h"

extern s32 func_L01_004F50E0(s32);

s32 func_L01_004F5108(u8 *arg0, s32 arg1, s32 *arg2) {
    f32 temp_f2;
    s32 var_a0;
    u8 var_a0_2;
    s32 var_v0;

    if (arg2 != NULL) {
        var_a0 = *arg2;
    } else {
        var_a0 = *(s16 *)(arg0 + arg1 * 2 + 0xC8);
    }
    if (func_L01_004F50E0(var_a0) == 0) {
        return 0;
    }
    temp_f2 = *(f32 *)(arg0 + arg1 * 4 + 0x2B4);
    if (temp_f2 > 0.0f) {
        var_a0_2 = 1;
        if (!((temp_f2 + 16.1f) < *(f32 *)(arg0 + arg1 * 0x10 + 0x278))) {
            var_a0_2 = 0;
        }
        var_v0 = 0;
        if (!var_a0_2) {
            goto block_9;
        }
    } else {
block_9:
        var_v0 = 1;
    }
    return var_v0;
}
