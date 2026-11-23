/* Not matching yet: PAL WIP; level_00 .text 0x00533AC0, 60B. Not part of the build. */
/*
 *  0x0008 lui $a2, 0xFFFF | addiu $a2, $zero, -0x1 0x000C ori $a2, $a2, 0xFFFF | nop 0x0010 lbu
 * $v0, 0x0($a0) | lbu $v1, 0x0($a0) 0x0014 lbu $v1, 0x0($a1) | lbu $v0, 0x0($a1) 0x0018 beq $v0,
 * $v1, . + 4 + (0x3 << 2) | beql $v1, $v0, . + 4 + (0x3 << 2) 0x001C addiu $a0, $a0, 0x1 | addiu
 * $a3, $a3, -0x1 0x0024 subu $v0, $v0, $v1 | subu $v0, $v1, $v0 0x0028 addiu $a3, $a3, -0x1 |
 * addiu $a0, $a0, 0x1
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: b889f2164f287b7936742532c91651aa1f33899c32fa711e81fa329f2b468e98
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_00533AC0 nonmatching/pal/l00_multiplayer_menu/func_L00_00533AC0.c --diff
 */
#include "common.h"

/* Bytewise comparator reconstructed from the PAL overlay and its callers. */
s32 func_L00_00533AC0(u8 *arg0, u8 *arg1, u32 arg2)
{
    u8 first;
    u8 second;

    while (arg2-- != 0) {
        first = *arg0;
        second = *arg1;
        if (first != second) {
            return first - second;
        }
        arg0++;
        arg1++;
    }
    return 0;
}
