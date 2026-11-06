#include "common.h"
f32 func_L02_004C3908(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((u8 *)(arg0) + 0xAC));
    return 1.0f - ((*(f32 *)((u8 *)(temp_v0) + 0x50)) / (f32) (*(s32 *)((u8 *)(temp_v0) + 0x54)));
}
