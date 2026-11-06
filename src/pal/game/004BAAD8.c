#include "common.h"

typedef void (*Action)(s32);
typedef s32 (*Predicate)(s32);
typedef struct State {
    s32 phase;
    s32 selected;
    s32 first;
    s32 second;
    s32 third;
} State;
extern u8 D_0030A490[];
extern u8 D_001CDB48[];
extern u8 D_003D95B0[];
extern s32 D_002218E0;
extern s32 func_00506BB8(void);
extern void func_004BB770(void);
extern s32 func_0049A9D8(void *descriptor, s32 owner);
extern s32 func_004A2798(s32 *group, s32 index);
extern s32 func_00506590(s32 handle, u32 value);
extern s32 func_005071B8(u32 handle, u32 resource);
extern void func_004BB438(void);
extern s32 func_00498280(s32 *selected, s32 count, Predicate predicate);
extern s32 func_004BB418(s32 index);
extern void func_0049DEA8(s32 context, s32 index, s32 handle);
extern void func_0049DFB8(s32 context, s32 count);
extern void func_0049D138(s32 context, s32 index, s32 group, s32 handle, s32 mode);
extern void func_0049CFC8(s32 context, s32 count);
extern void func_004BB4F0(void);

void func_004BAAD8(void)
{
    s32 context = func_00506BB8();
    State *state = (State *)((u32)context * 20 + (u32)D_0030A490);
    u32 descriptor;
    Action action;
    s32 group;

    func_004BB770();
    descriptor = (u32)D_001CDB48;
    state->first = func_0049A9D8((void *)descriptor, -1);
    descriptor += 8;
    func_00506590(func_004A2798(&D_002218E0, 7), 1);
    func_005071B8((u32)func_004A2798(&D_002218E0, 7), (u32)state->first);
    state->second = func_0049A9D8((void *)descriptor, -1);
    func_00506590(func_004A2798(&D_002218E0, 4), 1);
    func_005071B8((u32)func_004A2798(&D_002218E0, 4), (u32)state->second);
    state->third = func_0049A9D8((void *)(descriptor - 0x18), -1);
    func_00506590(func_004A2798(&D_002218E0, 1), 1);
    func_005071B8((u32)func_004A2798(&D_002218E0, 1), (u32)state->third);
    state->phase = 1;
    state->selected = 0;
    do {
        func_004BB438();
        action = *(Action *)((u32)D_003D95B0 + (u32)state->selected * 20);
        action(0);
        state->selected = (s32)((u32)state->selected + 1);
    } while (state->selected < 7);
    func_00498280(&state->selected, 7, func_004BB418);
    func_0049DEA8(context, 0, func_004A2798(&D_002218E0, 0x12));
    func_0049DFB8(context, 1);
    group = D_002218E0;
    func_0049D138(context, 0, group, func_004A2798(&D_002218E0, 0x12), 0);
    func_0049CFC8(context, 1);
    func_004BB4F0();
}
