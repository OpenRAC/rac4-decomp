#include "common.h"

typedef struct {
    u8 unknown0[8];
    u32 flags;
    s32 resourceC;
    s32 resource10;
    s32 resource14;
    s32 resource18;
    s32 resource1C;
    u8 tail[0x44];
} State;
extern State D_0030EAA0[];
extern s32 D_00221A20;
extern s32 func_00506BB8(void);
extern void func_0049D1E8(s32, s32, s32, s32);
extern void func_004CD620(void);
extern void func_0049AA18(s32);
extern void func_0049BE10(s32);

void func_004CCCB0(void)
{
    s32 index = func_00506BB8();
    State *state = (State *)((u32)D_0030EAA0 + (u32)index * 0x64);

    state->flags = 0;
    func_0049D1E8(index, 0, D_00221A20, 0);
    func_004CD620();
    if (state->resource10) {
        func_0049AA18(state->resource10);
        state->resource10 = 0;
    }
    if (state->resourceC) {
        func_0049AA18(state->resourceC);
        state->resourceC = 0;
    }
    if (state->resource14) {
        func_0049AA18(state->resource14);
        state->resource14 = 0;
    }
    if (state->resource18) {
        func_0049AA18(state->resource18);
        state->resource18 = 0;
    }
    if (state->resource1C) {
        func_0049AA18(state->resource1C);
        state->resource1C = 0;
    }
    func_0049BE10(index);
}
