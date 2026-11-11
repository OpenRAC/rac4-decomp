/* cflags:  -malign-jumps=3 */
#include "common.h"

void func_004E29B8(int, int);
void func_L04_004991A8(void *arg0, s32 arg1) {
    u16 temp_3;
    void *temp_4;

    if (arg1 != 0) {
        temp_4 = (*(void **)((u8 *)(arg0) + (0x24)));
        temp_3 = (*(u16 *)((u8 *)(arg0) + (0x34))) & 0xFFBE;
        (*(u16 *)((u8 *)(arg0) + (0x34))) = temp_3;
        (*(u16 *)((u8 *)(arg0) + (0x34))) = (u16) (temp_3 | ((*(u16 *)((u8 *)(temp_4) + (0x44))) & 0x1000));
        (*(s32 *)((u8 *)(arg0) + (0x98))) = (s32) (*(s32 *)((u8 *)(temp_4) + (0x10)));
        return;
    }
    (*(s32 *)((u8 *)(arg0) + (0x98))) = 0;
    (*(u16 *)((u8 *)(arg0) + (0x34))) = (u16) (((*(u16 *)((u8 *)(arg0) + (0x34))) | 0x41) & 0xEFFF);
    func_004E29B8((s32) arg0, 1);
}
