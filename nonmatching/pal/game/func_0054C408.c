/* Not matching yet: PAL WIP; main .text 0x0054C408, 168B. Not part of the build. */
/*
 *  0x0004 daddu $a1, $zero, $zero | sd $s0, 0x0($sp) 0x0008 sd $s0, 0x0($sp) | daddu $s0, $a0,
 * $zero 0x000C daddu $s0, $a0, $zero | sd $ra, 0x8($sp) 0x0010 beqz $s0, . + 4 + (0xA << 2) | beqz
 * $s0, . + 4 + (0xB << 2) 0x0014 sd $ra, 0x8($sp) | daddu $a0, $zero, $zero 0x0020 beq $v1, $v0, .
 * + 4 + (0x7 << 2) | beq $v1, $v0, . + 4 + (0x8 << 2) 0x0024 daddu $a0, $zero, $zero | andi $v0,
 * $a0, 0xFF 0x002C beqz $v0, . + 4 + (0x
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: e3d0119752fdfbbba08f6850109f56c1fb90272d3917ad5eef45a77ca479cab7
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0054C408 nonmatching/pal/game/func_0054C408.c --diff
 */
#include "common.h"

extern u32 D_0021DBCC;
extern s32 D_00220C30;
extern void *func_00511D30(u32 id);

void func_0054C408(void *arg0) {
    u32 temp_a1;
    u32 temp_v0_2;
    s32 var_a0;
    s32 var_v0;
    u8 *temp_v0;
    u8 *temp_v0_3;
    u8 *record;
    s32 current;

    var_a0 = 0;
    if (arg0 != NULL) {
        var_v0 = 0 & 0xFF;
        if (*(s32 *)((u8 *)arg0 + 0x25CC) != 0x9B) {
            temp_v0 = *(u8 **)((u8 *)arg0 + 0x2F28);
            if (temp_v0 != NULL) {
                var_a0 = *(u8 **)(temp_v0 + 4) != NULL;
            }
            goto block_4;
        }
    } else {
block_4:
        var_v0 = var_a0 & 0xFF;
    }
    if (var_v0 != 0 && *((u8 *)arg0 + 0x266D) == 0) {
        temp_v0 = *(u8 **)((u8 *)arg0 + 0x2F28);
        temp_a1 = D_0021DBCC;
        record = *(u8 **)(temp_v0 + 4);
        current = D_00220C30;
        temp_v0_2 = *(u32 *)(record + 0x50) ^ temp_a1;
        if (temp_v0_2 != current) {
            temp_v0_3 = func_00511D30(temp_v0_2);
            if (temp_v0_3 != NULL) {
                *(u32 *)((u8 *)arg0 + 0x1848) = *(u32 *)(temp_v0_3 + 0x2EF0);
            }
        }
    }
}
