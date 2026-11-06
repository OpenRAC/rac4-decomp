#include "common.h"

extern s32 D_0021DE40;
extern void func_00451A90(s32, s32 *, s32, s32, s32);

void func_00452DC0(s32 arg0, s32 *state, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    s32 i;
    s32 *entry;
    state[0xA8 / 4] = D_0021DE40;
    state[0xAC / 4] = 0;
    for (i = 0; i < 32 && state[i + 4] != 0; i++) {
        entry = (s32 *)state[i + 4];
        func_00451A90(arg0, entry, arg2, arg3, arg4);
        *(u8 *)((u8 *)entry + 0xB) = 1;
    }
    state[0xA4 / 4] = i;
    if (arg5 != 0) {
        *(f32 *)((u8 *)state + 0x90) = 1.0f;
        *(f32 *)((u8 *)state + 0x94) = 1.0f;
        state[0x98 / 4] = 0;
        state[0x9C / 4] = 0;
        *(f32 *)((u8 *)state + 0xA0) = 1.0f;
    }
}
