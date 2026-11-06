#include "common.h"

typedef struct State {
    u8 prefix[8];
    s32 delay;
    u8 active;
    u8 rest[0x527];
} State;

extern State D_0030A6F0[];
extern u8 D_0021F93A;
extern u8 D_0021F938;
extern u8 D_0021F939;
extern s32 func_00505B20(void);
extern void func_00498CF8(void);
extern void func_0049D280(s32 context, s32 count);
extern void func_0049C290(s32 context, s32 count);
extern void func_0049B148(s32 context, s32 mode);

void func_004BB958(void)
{
    s32 context = func_00505B20();
    State *state = (State *)((u32)D_0030A6F0 + (u32)context * sizeof(State));
    func_00498CF8();
    D_0021F93A = 0;
    D_0021F938 = 0;
    D_0021F939 = 0;
    func_0049D280(context, 0);
    func_0049C290(context, 0);
    state->delay = 30;
    state->active = 1;
    func_0049B148(context, 0);
}
