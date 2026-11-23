/* Not matching yet: PAL WIP; level_01 .text 0x006B1460, 52B. Not part of the build. */
/*
 *  0x0000 addiu $v1, $zero, 0x50 | addiu $v0, $zero, 0x50 0x0004 lw $a2, 0x2F00($a0) | mult $v1,
 * $a1, $v0 0x0008 mult $v0, $a1, $v1 | addu $a1, $v1, $a0 0x000C addu $a0, $v0, $a0 | lw $v1,
 * 0x2F00($a0) 0x0010 lw $v0, 0x1A0($a2) | lw $a0, 0x2300($a1) 0x0014 lw $v1, 0x2300($a0) | lw $v0,
 * 0x1A0($v1) 0x0018 and $v0, $v0, $v1 | and $v0, $v0, $a0 0x001C bnez $v0, . + 4 + (0x4 << 2) |
 * beqz $v0, . + 4 + (0x3 << 2) 0x0020 addiu
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: fbee88c309227ab3e03a893ad59b70192caf1c17723dd9b9863318d48944014c
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_006B1460 nonmatching/pal/shared/func_L01_006B1460.c --diff
 */
#include "common.h"

/* Refresh the row byte from its mask and linked flags, preserving status 1. */
s32 func_L01_006B1460(void *arg0, s32 arg1)
{
    u8 *base;
    u8 *row;
    u8 *linked;
    u32 mask;
    u32 flags;

    base = arg0;
    row = base + arg1 * 0x50;
    linked = *(u8 **)(base + 0x2F00);
    mask = *(u32 *)(row + 0x2300);
    flags = *(u32 *)(linked + 0x1A0);
    if (flags & mask) {
        row[0x22F8] = 1;
        return 1;
    }
    row[0x22F8] = 0;
    return 1;
}
