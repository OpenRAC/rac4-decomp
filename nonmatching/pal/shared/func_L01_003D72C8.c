/* Not matching yet: PAL WIP; level_01 .text 0x003D72C8, 124B. Not part of the build. */
/*
 *  0x0018 daddu $a3, $zero, $zero | daddu $t1, $v0, $zero 0x0020 lbu $t1, 0x1E1($v0) | daddu $a1,
 * $zero, $zero 0x0028 addiu $a2, $v0, 0xD0 | daddu $a3, $v1, $zero 0x002C daddu $a1, $v1, $zero |
 * addiu $a2, $t1, 0xD0 0x003C addiu $a1, $a1, -0x1 | addiu $a3, $a3, -0x1 0x0044 addiu $a0, $a3,
 * 0x1 | addiu $a0, $a1, 0x1 0x004C movn $a3, $a0, $v1 | movn $a1, $a0, $v1 0x0050 bnez $a1, . + 4
 * + (-0x9 << 2) | bnez $a3, . + 4 + (-0
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 9b56f3e7eadc9ab471f07354ab432150c20f3b72c5225a4f2d6113398c23cbea
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_003D72C8 nonmatching/pal/shared/func_L01_003D72C8.c --diff
 */
#include "common.h"

s32 func_L01_003D72C8(void *object)
{
    u8 *owner = *(u8 **)((u8 *)object + 0xAC);
    u8 *group = *(u8 **)(owner + 0x320);
    s32 count;
    s32 matching;

    if (group == NULL)
        return 1;
    count = *(s32 *)(group + 0x110);
    matching = 0;
    if (count > 0) {
        s16 ownClass = *(s16 *)((u8 *)object + 0xBC);
        void **slot = (void **)(group + 0xD0);
        s32 remaining = count;
        do {
            u8 *node = *slot;
            s16 nodeClass = *(s16 *)(node + 0xBC);
            --remaining;
            if (nodeClass == ownClass) {
                u8 *state = *(u8 **)(node + 0xAC);
                if (*(u8 *)(state + 0x4DD) != 0)
                    ++matching;
            }
            ++slot;
        } while (remaining != 0);
    }
    if (matching < *(u8 *)(group + 0x1E1)) {
        *(u8 *)(owner + 0x4DD) = 1;
        return 1;
    }
    return 0;
}
