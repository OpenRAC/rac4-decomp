#include "common.h"

typedef struct State {
    u8 pad0[12];
    s32 direction;
    f32 phase0, phase1;
    u8 pad18[0x5C];
    s32 first;
    u8 pad78[0x1C];
    s32 second;
} State;
extern u8 D_00308208[];
extern s32 D_00221750;
extern s32 func_00506BB8(void);
extern s32 func_00499650(s32 selector, s32 mode);
extern u32 func_004993A8(f32 *phase, u32 first, f32 step, u32 second);
extern s32 func_004A2798(s32 *base, s32 offset);
extern s32 func_005063C0(s32 handle, u32 color);
extern s32 func_004996F8(s32 context, s32 mode);
void func_004A8FF0(void)
{
    s32 index = func_00506BB8();
    State *state = (State *)((u32)D_00308208 + (u32)index * 0xB8);
    u32 color = 0x40000000;
    s32 value = state->direction;
    if (value != 0) {
        u32 target;
        if (value > 0)
            target = func_00499650(0, 1);
        else
            target = func_00499650(1, 1);
        target = (target & 0x00FFFFFF) | 0x40000000;
        color = func_004993A8(&state->phase0, 0x40000000, 0.01f, target);
    }
    func_005063C0(func_004A2798(&D_00221750, 0x2C), color);
    color = 0x80D0D0D0;
    if (state->first <= 0 && state->second > 0) {
        u32 target = func_004996F8(index, 0);
        color = func_004993A8(&state->phase1, target, 0.05f, 0x80D0D0D0);
    }
    func_005063C0(func_004A2798(&D_00221750, 0x30), color);
}
