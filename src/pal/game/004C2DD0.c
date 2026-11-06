#include "common.h"

typedef struct State {
    s32 phase, unknown04;
    u32 flags;
    s32 choice, mode;
} State;
extern u8 D_0030B7F8[];
extern s32 func_00506BB8(void);
extern void func_00502520(void *descriptor);
extern void func_004C5030(void);
extern void func_004C5310(void);
extern void func_004C54C0(void);
extern void func_0049CF80(s32 context, s32 channel);
extern void func_0049D0C8(s32 context, s32 channel);
extern void func_0049D060(s32 context, s32 channel, s32 enabled);
extern void func_004C2FC8(void);
extern void func_004C3010(void);
extern void func_004C37C8(void);
extern void func_004C3A08(void);
extern void func_004C3578(void);
extern void func_004C32B8(void);
extern void func_004C3380(void);
extern void func_004C3C10(void);

void func_004C2DD0(void *descriptor)
{
    s32 context = func_00506BB8();
    State *state = (State *)((u32)D_0030B7F8 + (u32)context * 0x74u);

    switch (state->phase) {
    case 0:
        state->phase = 1;
        break;
    case 1:
        func_004C5030();
        break;
    case 2:
        func_004C5310();
        break;
    case 3:
        func_004C54C0();
        break;
    case 4:
        func_00502520(descriptor);
        break;
    }
    if (state->phase == 1) {
        if (state->mode == 0) {
            func_0049CF80(context, 2);
            func_0049D0C8(context, 1);
            func_0049D060(context, 0, 1);
        } else {
            func_0049CF80(context, 2);
            func_0049D0C8(context, 0);
            func_0049D060(context, 1, 1);
        }
    } else {
        func_0049D0C8(context, 0);
        func_0049D0C8(context, 1);
    }
    if (state->flags & 1)
        func_004C2FC8();
    if (state->flags & 2)
        func_004C3010();
    if (state->flags & 0x10)
        func_004C37C8();
    if (state->flags & 0x40)
        func_004C3A08();
    if (state->flags & 0x20)
        func_004C3578();
    if (state->flags & 4)
        func_004C32B8();
    if (state->flags & 8)
        func_004C3380();
    if (state->flags & 0x80)
        func_004C3C10();
}
