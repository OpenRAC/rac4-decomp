#include "common.h"

extern s32 func_00472E70(s32, s32);
extern s32 func_L01_0044A2A8(void *object);
extern void func_00474368(void *, s32, s32);

// PAL version of func_L01_0044AA78: initialize the timer and state for the selected
// object action; the random frame count is converted to 50 Hz ((n * 5 + 2) / 6).
void func_L01_0044BBA0(void *object, s32 value, f32 timer) {
    u8 *linked;
    s32 state;

    if (*(s16 *)((u8 *)object + 0xBC) != 0x20F0) return;
    linked = *(u8 **)((u8 *)object + 0xAC);
    func_L01_0044A2A8(object);
    state = *(s16 *)(linked + 0xF2);
    if (state != 0) return;
    *(f32 *)(linked + 0x108) = 0.0f;
    if (*(f32 *)(linked + 0x108) < timer) *(f32 *)(linked + 0xF4) = timer;
    func_00474368(object, 1, -1);
    *(s16 *)(linked + 0xF0) = value;
    linked[0x105] = 0;
    linked[0x106] = 0;
    *(s16 *)(linked + 0xF2) = 1;
    *(s32 *)(linked + 0x120) = (func_00472E70(0, 0x1E) * 5 + 2) / 6;
}
