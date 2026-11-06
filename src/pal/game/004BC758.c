#include "common.h"

typedef struct State {
    u8 prefix[8];
    s32 delay;
    u8 active;
    u8 rest[0x527];
} State;

extern State D_0030A6F0[];
extern u8 D_0021F9DA;
extern u8 D_0021F9D8;
u8 D_0021F9D9 = 0;
extern s32 func_00506BB8(void);
extern void func_00499A30(void);
extern void func_0049DFB8(s32 context, s32 count);
extern void func_0049CFC8(s32 context, s32 count);
extern void func_0049BE80(s32 context, s32 mode);

void func_004BC758(void)
{
    s32 context = func_00506BB8();
    State *state = (State *)((u32)D_0030A6F0 + (u32)context * sizeof(State));
    func_00499A30();
    D_0021F9DA = 0;
    D_0021F9D8 = 0;
    D_0021F9D9 = 0;
    func_0049DFB8(context, 0);
    func_0049CFC8(context, 0);
    state->delay = 30;
    state->active = 1;
    func_0049BE80(context, 0);
}
