#include "common.h"

typedef struct {
    u8 p0[0xD4];
    f32 fD4, fD8;
    union {
        f32 value;
        s32 bits;
    } fDC;
    s32 fE0;
    u8 tail[0x38C];
} State;
extern State D_00229CE0[];
extern f32 D_002211E0;
extern f32 func_004757A0(f32 *, f32, f32);
extern s32 func_004534D0(s32 *);
void func_0043D250(s32 index)
{
    State *state = (State *)((u32)D_00229CE0 + (u32)index * 0x470);
    if (state->fD4 != 0.0f) {
        if (state->fDC.value != 0.0f)
            func_004757A0((f32 *)((u32)index * 4 + (u32)&D_002211E0), state->fDC.value, state->fD4);
        else
            func_004757A0((f32 *)((u32)index * 4 + (u32)&D_002211E0), state->fDC.value, state->fD8);
        if (*(f32 *)((u32)index * 4 + (u32)&D_002211E0) == state->fDC.value) {
            if (func_004534D0(&state->fE0) == 1)
                state->fDC.bits = 0;
        }
        if (state->fDC.value <= 0.0f && *(f32 *)((u32)index * 4 + (u32)&D_002211E0) <= 0.0f)
            state->fD4 = 0.0f;
    }
}
