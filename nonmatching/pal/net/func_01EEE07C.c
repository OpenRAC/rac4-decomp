/* Not matching yet: PAL WIP; main net.text 0x01EEE07C, 64B. Not part of the build. */
/*
 *  0x0000 addiu $v0, $zero, 0x20 | addiu $v1, $zero, 0x20 0x0004 beq $a0, $v0, . + 4 + (0xC << 2)
 * | beq $a0, $v1, . + 4 + (0xC << 2) 0x0008 daddu $v1, $zero, $zero | addiu $v0, $zero, 0x1 0x000C
 * addiu $v0, $zero, 0xC | addiu $v1, $zero, 0xC 0x0010 beq $a0, $v0, . + 4 + (0x9 << 2) | beq $a0,
 * $v1, . + 4 + (0x9 << 2) 0x0014 addiu $v0, $zero, 0xA | addiu $v1, $zero, 0xA 0x0018 beq $a0,
 * $v0, . + 4 + (0x7 << 2) | beq $a0, $v
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: dc8027f06874aac89795f4dbfb46a03bd78d4ac1877f14f8252f44182246ab36
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EEE07C nonmatching/pal/net/func_01EEE07C.c --diff
 */
#include "common.h"

/* Test the six native scalar values in their short-circuit order. */
s32 func_01EEE07C(s32 c)
{
    return c == 0x20 || c == 0xC || c == 0xA ||
           c == 0xD || c == 9 || c == 0xB;
}
