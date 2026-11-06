#include "common.h"

typedef void (*Action)(s32 direction);
typedef s32 (*Predicate)(s32 index);
typedef struct State {
    s32 phase;
    s32 selected;
    s32 first;
    s32 second;
} State;
extern u8 D_0030A260[];
extern u8 D_001CDB20[];
extern u8 D_003D93F8[];
extern s32 D_00221890;
extern s32 func_00506BB8(void);
extern void func_004B9B40(void);
extern s32 func_0049A9D8(void *descriptor, s32 owner);
extern s32 func_004A2798(s32 *group, s32 index);
extern s32 func_00506590(s32 handle, u32 value);
extern s32 func_005071B8(u32 handle, u32 resource);
extern void func_004B9818(void);
extern s32 func_00498280(s32 *selected, s32 count, Predicate predicate);
extern s32 func_004B97F8(s32 index);
extern void func_0049DEA8(s32 context, s32 index, s32 handle);
extern void func_0049DFB8(s32 context, s32 count);
extern void func_0049D138(s32 context, s32 index, s32 group, s32 handle, s32 mode);
extern void func_0049CFC8(s32 context, s32 count);
extern void func_004B98D0(void);

void func_004B8D68(void)
{
    s32 context = func_00506BB8();
    State *state = (State *)((u32)D_0030A260 + (u32)context * sizeof(State));
    u32 descriptor;
    Action action;
    s32 group;

    func_004B9B40();
    descriptor = (u32)D_001CDB20;
    state->first = func_0049A9D8((void *)descriptor, -1);
    func_00506590(func_004A2798(&D_00221890, 1), 1);
    func_005071B8((u32)func_004A2798(&D_00221890, 1), (u32)state->first);
    descriptor += 0x18;
    state->second = func_0049A9D8((void *)descriptor, -1);
    func_00506590(func_004A2798(&D_00221890, 2), 1);
    func_005071B8((u32)func_004A2798(&D_00221890, 2), (u32)state->second);
    state->phase = 1;
    state->selected = 0;
    do {
        func_004B9818();
        action = *(Action *)((u32)D_003D93F8 + (u32)state->selected * 20u);
        action(0);
        state->selected = (s32)((u32)state->selected + 1u);
    } while (state->selected < 6);
    func_00498280(&state->selected, 6, func_004B97F8);
    func_0049DEA8(context, 0, func_004A2798(&D_00221890, 16));
    func_0049DFB8(context, 1);
    group = D_00221890;
    func_0049D138(context, 0, group, func_004A2798(&D_00221890, 16), 0);
    func_0049CFC8(context, 1);
    func_004B98D0();
}
