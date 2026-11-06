#include "common.h"
void func_L00_00722C68(void *arg0) {
    s32 temp_v0;

    temp_v0 = (*(s32 *)((u8 *)(arg0) + 0x260)) + 1;
    (*(s32 *)((u8 *)(arg0) + 0x260)) = temp_v0;
    if ((f32) temp_v0 > 900.0f) {
        (*(s32 *)((u8 *)(arg0) + 0x260)) = 0;
        (*(s8 *)((u8 *)(arg0) + 0x264)) = 1;
    }
}
