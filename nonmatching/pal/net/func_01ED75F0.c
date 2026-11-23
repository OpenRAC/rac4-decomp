/* Not matching yet: PAL WIP; main net.text 0x01ED75F0, 100B. Not part of the build. */
/*
 *  0x0000 addiu $sp, $sp, -0x10 | daddu $a3, $a0, $zero 0x0004 sd $ra, 0x0($sp) | addiu $a0,
 * $zero, 0x1 0x0008 addiu $v1, $zero, 0x1 | addiu $sp, $sp, -0x10 0x000C sb $zero, 0x10($a0) | lui
 * $a1, 0x17 0x0010 sb $zero, 0x57($a0) | sd $ra, 0x0($sp) 0x0014 sb $zero, 0x77($a0) | sb $zero,
 * 0x10($a3) 0x0018 lui $v0, 0x17 | sb $zero, 0x57($a3) 0x001C lw $v0, -0x62B0($v0) | sb $zero,
 * 0x77($a3) 0x0020 bne $v0, $v1, . + 4 + (0xC
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 8cbaf8ca790bc8537847545250fbf7234c5d32cd58d515ccacc700d42bb77a6e
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01ED75F0 nonmatching/pal/net/func_01ED75F0.c --diff
 */
#include "common.h"

extern s32 D_00169D50_pal_state;
extern s32 D_00169D54_pal_handle;
extern s32 func_01ED5DD0(s32, s32, s32, s32);

s32 func_01ED75F0(void *request)
{
    s32 result = -15;
    *((u8 *)request + 0x10) = 0;
    *((u8 *)request + 0x57) = 0;
    *((u8 *)request + 0x77) = 0;
    if (D_00169D50_pal_state == 1) {
        result = -16;
        if (D_00169D54_pal_handle != 0) {
            s32 call_result = func_01ED5DD0(1, 2, 0x7C, (s32)request);
            result = -5;
            if (call_result == 0) {
                result = 0;
            }
        }
    }
    return result;
}
