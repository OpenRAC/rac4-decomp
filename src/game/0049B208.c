#include "common.h"

typedef struct State {
    u8 unknown0[4];
    s32 mode;
    s32 nextMode;
    s32 depth;
    u8 history[0x2C];
} State;
typedef struct Mode {
    u32 unknown0;
    void (*leave)(s32 context);
    u32 unknown8[2];
} Mode;
extern State D_00306DC0[];
extern Mode D_003D8E68[];
extern s32 D_0021EDD4;
extern void func_0049B148(s32 context, s32 mode);
extern void func_0049B2F8(s32 context, s32 mode);

static inline u32 addressAdd(u32 base, u32 offset)
{
    return base + offset;
}

void func_0049B208(s32 inputContext)
{
    s32 context = 0;
    State *state;
    void (*leave)(s32);
    if (D_0021EDD4 == 1) {
        context = inputContext;
    }
    state = (State *)((u32)D_00306DC0 + (u32)context * sizeof(State));
    leave = ((Mode *)((u32)D_003D8E68 + (u32)state->mode * sizeof(Mode)))->leave;
    if (leave) {
        leave(context);
    }
    if (state->depth > 0) {
        state->depth--;
        func_0049B148(context, *(s32 *)(addressAdd((u32)state, (u32)state->depth * 4) + 0x10));
    } else {
        func_0049B2F8(context, -1);
    }
}
