#include "common.h"

typedef struct State {
    s32 phase, unknown04;
    u32 flags;
    s32 choice, mode;
} State;
extern u8 D_0030B7F8[];
extern s32 func_00505B20(void);
extern void func_005014B0(void *descriptor);
extern void func_004C4208(void);
extern void func_004C44E8(void);
extern void func_004C4698(void);
extern void func_0049C248(s32 context, s32 channel);
extern void func_0049C390(s32 context, s32 channel);
extern void func_0049C328(s32 context, s32 channel, s32 enabled);
extern void func_004C21A0(void);
extern void func_004C21E8(void);
extern void func_004C29A0(void);
extern void func_004C2BE0(void);
extern void func_004C2750(void);
extern void func_004C2490(void);
extern void func_004C2558(void);
extern void func_004C2DE8(void);

void func_004C1FA8(void *descriptor)
{
    s32 context = func_00505B20();
    State *state = (State *)((u32)D_0030B7F8 + (u32)context * 0x74u);

    switch (state->phase) {
    case 0:
        state->phase = 1;
        break;
    case 1:
        func_004C4208();
        break;
    case 2:
        func_004C44E8();
        break;
    case 3:
        func_004C4698();
        break;
    case 4:
        func_005014B0(descriptor);
        break;
    }
    if (state->phase == 1) {
        if (state->mode == 0) {
            func_0049C248(context, 2);
            func_0049C390(context, 1);
            func_0049C328(context, 0, 1);
        } else {
            func_0049C248(context, 2);
            func_0049C390(context, 0);
            func_0049C328(context, 1, 1);
        }
    } else {
        func_0049C390(context, 0);
        func_0049C390(context, 1);
    }
    if (state->flags & 1)
        func_004C21A0();
    if (state->flags & 2)
        func_004C21E8();
    if (state->flags & 0x10)
        func_004C29A0();
    if (state->flags & 0x40)
        func_004C2BE0();
    if (state->flags & 0x20)
        func_004C2750();
    if (state->flags & 4)
        func_004C2490();
    if (state->flags & 8)
        func_004C2558();
    if (state->flags & 0x80)
        func_004C2DE8();
}
