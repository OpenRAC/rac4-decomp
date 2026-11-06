#include "common.h"
s32 func_L01_00409B20(f32, f32);                /* extern */

void func_L01_0040A600(void *arg0) {
    f32 temp_f12;

    temp_f12 = (f32) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0xAC))) + 0xF2)) / 25.0f;
    func_L01_00409B20(temp_f12, temp_f12);
}
