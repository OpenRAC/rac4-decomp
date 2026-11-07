/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 D_0021DE3C[];

void func_L00_006D4A90(void *arg0, void *arg1) {
    if ((u8) (*(u8 *)((s8 *)(arg1) + (0x54))) < 3U) {

        (*(s8 *)((s8 *)(arg1) + (0x31))) = 0;
        (*(u16 *)((s8 *)(arg1) + (0x34))) = (u16) ((*(u16 *)((s8 *)(arg1) + (0x34))) | 1);
        return;
    }
    if ((*(s32 *)((s8 *)(arg0) + (0x2EE8))) != 0) {

        (*(s8 *)((s8 *)(arg1) + (0x31))) = 0;
        (*(u16 *)((s8 *)(arg1) + (0x34))) = (u16) ((*(u16 *)((s8 *)(arg1) + (0x34))) | 1);
        return;
    }
    if (D_0021DE3C[0] != 2) {
        (*(s8 *)((s8 *)(arg1) + (0x31))) = 1;
        (*(u16 *)((s8 *)(arg1) + (0x34))) = (u16) ((*(u16 *)((s8 *)(arg1) + (0x34))) & 0xFFFE);
        return;
    }
    (*(s8 *)((s8 *)(arg1) + (0x31))) = 0;
    (*(u16 *)((s8 *)(arg1) + (0x34))) = (u16) ((*(u16 *)((s8 *)(arg1) + (0x34))) | 1);
}
