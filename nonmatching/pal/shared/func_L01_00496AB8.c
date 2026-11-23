/* Not matching yet: PAL WIP; level_01 .text 0x00496AB8, 108B. Not part of the build. */
/*
 *  0x000C addiu $v0, $v0, 0xD0 | addiu $v1, $v0, 0xD0 0x0010 lw $a3, 0x40($v0) | lw $v0, 0x40($v1)
 * 0x0014 blez $a3, . + 4 + (0x13 << 2) | blez $v0, . + 4 + (0x13 << 2) 0x0018 daddu $a1, $v0,
 * $zero | daddu $a2, $zero, $zero 0x001C daddu $a2, $zero, $zero | daddu $a3, $v0, $zero 0x0020
 * addiu $t0, $zero, 0x2570 | daddu $a1, $v1, $zero 0x0024 nop | addiu $t0, $zero, 0x2570 0x0038
 * bne $v0, $t0, . + 4 + (0x8 << 2) | bne $v0,
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 78ad97091a0e6e46423e067797f7598a8b93407a26429063fed53efd10349fad
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_00496AB8 nonmatching/pal/shared/func_L01_00496AB8.c --diff
 */
#include "common.h"
s32 func_L01_00496AB8(void *object)
{
    u8 *owner = *(u8 **)((u8 *)object + 0xAC);
    u8 *group = *(u8 **)(owner + 0x410);
    if (group != NULL) {
        void **table = (void **)(group + 0xD0);
        s32 count = *(s32 *)((u8 *)table + 0x40);
        if (count > 0) {
            void **slot = table;
            s32 index = 0;
            do {
                void *node = *slot;
                index++;
                if (node != object && *(s16 *)((u8 *)node + 0xBC) == 0x2570) {
                    if (*(s16 *)(*(u8 **)((u8 *)node + 0xAC) + 0x4D6) == 0)
                        return 1;
                }
                slot++;
            } while (index < count);
        }
    }
    return 0;
}
