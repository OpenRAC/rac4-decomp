#include "common.h"
void func_L01_00462D70(void *arg0) {
    f32 temp_f0;
    void *temp_v0;

    temp_v0 = (*(void **)((u8 *)(arg0) + 0xAC));
    temp_f0 = (*(f32 *)((u8 *)(temp_v0) + 8)) + (*(f32 *)((u8 *)(temp_v0) + 0xC));
    (*(f32 *)((u8 *)(temp_v0) + 8)) = temp_f0;
    if (temp_f0 > 1.0f) {
        (*(f32 *)((u8 *)(temp_v0) + 8)) = (f32) (temp_f0 - 1.0f);
    }
}
