#include "common.h"
void func_L01_00440C48(void *arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = (*(void **)((u8 *)(arg0) + 0xAC));
    (*(f32 *)((u8 *)(temp_v0) + 0x58)) = 1.0f;
    (*(f32 *)((u8 *)(temp_v0) + 0x4C)) = 1.0f;
    (*(s8 *)((u8 *)((temp_v0 + arg1)) + 0x40)) = 0;
}
