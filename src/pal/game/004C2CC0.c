#include "common.h"

typedef struct {
    u8 prefix[8];
    s32 f8;
    u8 pC[0x5C];
    s32 f68, f6C, f70;
} State;
extern State D_0030B7F8[];
extern s32 D_00221980;
extern s32 D_00221988;
extern s32 func_0045E618(void);
extern s32 func_00506BB8(void);
extern void func_0049D1E8(s32, s32, s32, s32);
extern void func_004C6398(void);
extern void func_0049AA18(s32);
extern void func_0049BE10(s32);
void func_004C2CC0(void)
{
    s32 index;
    State *state;
    func_0045E618();
    index = func_00506BB8();
    state = (State *)((u32)D_0030B7F8 + (u32)index * 0x74);
    state->f8 = 0;
    func_0049D1E8(index, 0, D_00221980, 0);
    func_0049D1E8(index, 1, D_00221980, 0);
    func_0049D1E8(index, 2, D_00221988, 0);
    func_0049D1E8(index, 3, D_00221988, 0);
    func_004C6398();
    if (state->f70) {
        func_0049AA18(state->f70);
        state->f70 = 0;
    }
    if (state->f68) {
        func_0049AA18(state->f68);
        state->f68 = 0;
    }
    if (state->f6C) {
        func_0049AA18(state->f6C);
        state->f6C = 0;
    }
    func_0049BE10(index);
}
