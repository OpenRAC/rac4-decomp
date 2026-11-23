/* Not matching yet: PAL WIP; main net.text 0x01EA3B10, 116B. Not part of the build. */
/*
 *  0x0004 sd $s0, 0x0($sp) | addiu $v0, $zero, 0x17 0x0008 sd $ra, 0x8($sp) | beqz $a0, . + 4 +
 * (0x17 << 2) 0x000C beqz $a0, . + 4 + (0x17 << 2) | sd $ra, 0x0($sp) 0x0010 addiu $s0, $zero,
 * 0x17 | lw $v1, 0x468($a0) 0x0014 lw $v1, 0x468($a0) | addiu $v0, $zero, 0x2 0x0018 addiu $v0,
 * $zero, 0x2 | beq $v1, $v0, . + 4 + (0xB << 2) 0x001C beq $v1, $v0, . + 4 + (0xA << 2) | lui $v0,
 * 0x16 0x0020 lw $v1, 0x0($gp) | lw $v1, 0x7
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 4043b68d37776d182990d895914ac7860ee705a93d8e9ee130207b9de36bc2ce
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EA3B10 nonmatching/pal/net/func_01EA3B10.c --diff
 */
#include "common.h"

extern u8 *D_00167FAC;
extern u8 *D_00167FBC;
s32 func_01EA42D8(s32);

s32 func_01EA3B10(void *arg0, s32 flag) {
    s32 temp_v0;
    s32 var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        if (*(s32 *)((u8 *)arg0 + 0x468) != 2) {
            temp_v0 = func_01EA42D8((*(s32 (**)(s32, s32))(D_00167FAC + 0x40))(*(s32 *)((u8 *)arg0 + 0x470), flag));
            if (temp_v0 != 0) {
                return temp_v0;
            }
            goto block_5;
        }
        var_v0 = 0x25;
        if ((*(s32 (**)(s32, s32))(D_00167FBC + 0x4C))(*(s32 *)((u8 *)arg0 + 0x474), flag) == 0) {
block_5:
            var_v0 = 0;
        }
        goto block_6;
    }
block_6:
    return var_v0;
}
