#include "common.h"
s32 func_L01_00475F18(f32, f32);                /* extern */

void func_L01_004769F8(void *arg0) {
    f32 temp_f12;

    temp_f12 = (f32) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0xAC))) + 0xF6)) / 15.0f;
    func_L01_00475F18(temp_f12, temp_f12);
}
