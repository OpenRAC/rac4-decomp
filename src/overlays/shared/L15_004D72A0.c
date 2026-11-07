#include "common.h"

extern s32 D_0039FE50[];

void func_L15_004D72A0(s32 arg0) {
    s32 *temp_a1;

    temp_a1 = (void *)(((arg0 >> 5) * 4) + (u8 *)D_0039FE50);
    *temp_a1 &= ~(1 << (arg0 & 0x1F));
}
