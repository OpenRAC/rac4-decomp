/* Not matching yet: PAL WIP; main .text 0x0044B728, 136B. Not part of the build. */
/*
 *  0x0000 lui $a1, 0x0 | lui $v1, 0x22 0x0004 lw $a1, 0x0($a1) | lw $v1, -0x21D4($v1) 0x000C lw
 * $v0, 0x0($a1) | lw $v0, 0x0($v1) 0x0010 blez $v0, . + 4 + (0x19 << 2) | blez $v0, . + 4 + (0x1B
 * << 2) 0x0014 daddu $a2, $zero, $zero | daddu $a0, $zero, $zero 0x0024 addiu $a0, $v0, 0x0 |
 * addiu $v0, $v0, -0x6220 0x0028 lui $v1, 0x0 | daddu $a2, $v1, $zero 0x002C addiu $v1, $v1, 0x0 |
 * add.s $f1, $f12, $f0 0x0030 add.s $f1, $f
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 320f17ac7f2c250763692cbbb3f7559e4001460495dc415b3eed6a2e9bfe4ef4
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0044B728 nonmatching/pal/game/func_0044B728.c --diff
 */
#include "common.h"

typedef struct {
    u8 prefix[0xC8];
    f32 fC8, fCC;
    s32 fD0;
    u8 tail[0x39C];
} State;
extern State D_00229DE0[];
extern f32 D_002212D0;
extern s32 *D_0021DE2C;

s32 func_0044B728(f32 fparg0)
{
    f32 *var_v1;
    f32 temp_f0;
    f32 temp_f1;
    s32 *temp_v1;
    State *var_a1;
    s32 var_a0;
    s32 var_a3;

    temp_v1 = D_0021DE2C;
    var_a3 = 1;
    var_a0 = 0;
    if (*temp_v1 > 0) {
        temp_f1 = fparg0 + 1.0f;
        var_a1 = D_00229DE0;
        var_v1 = &D_002212D0;
        do {
            temp_f0 = *var_v1;
            var_a1->fC8 = 0.0f;
            temp_f0 = temp_f0 + fparg0;
            *var_v1 = temp_f0;
            if (temp_f1 <= temp_f0) {
                *var_v1 = temp_f1;
            } else {
                var_a3 = 0;
            }
            var_a0 += 1;
            var_v1 += 1;
            var_a1 += 1;
        } while (var_a0 < *temp_v1);
    }
    return var_a3;
}
