#include "common.h"

typedef struct {
    u8 prefix[0xC8];
    f32 fC8, fCC;
    s32 fD0;
    u8 tail[0x39C];
} State;
extern State D_00229DE0[];
extern f32 D_002212D0;
extern f32 func_00476080(f32 *, f32, f32);
extern s32 func_00453CE8(s32 *);
void func_0043D788(s32 index)
{
    State *state = (State *)((u32)D_00229DE0 + (u32)index * 0x470);
    if (state->fC8 != 0.0f) {
        f32 *value = (f32 *)((u32)index * 4 + (u32)&D_002212D0);
        func_00476080(value, state->fCC, state->fC8);
        if (*value == state->fCC) {
            if (func_00453CE8(&state->fD0) == 1)
                state->fCC = 0.0f;
        }
        if (state->fCC <= 0.0f && *(f32 *)((u32)index * 4 + (u32)&D_002212D0) <= 0.0f)
            state->fC8 = 0.0f;
    }
}
