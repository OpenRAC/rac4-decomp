#include "common.h"
extern s32 D_00222A90;
void func_L01_00526828(s32 index) {
    u8 *entry = (u8 *)(((u32)index << 5) + (u32)D_00222A90);
    u8 *target = *(u8 **)(entry + 0x1C);
    target[0xB2] = 0;
}