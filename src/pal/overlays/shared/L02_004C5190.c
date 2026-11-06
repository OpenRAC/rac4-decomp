#include "common.h"

typedef struct Obj Obj;
extern void func_00473A88(Obj *object, u8 state, s32 type);

s32 func_L02_004C5190(u8 *object)
{
    u8 *state;
    if (*(u8 *)(object + 0x20) != 0)
        return 0;
    state = *(u8 **)(object + 0xAC);
    *(u32 *)(object + 0x98) = *(u32 *)(*(u8 **)(object + 0x24) + 0x10);
    if (*(s32 *)(state + 0x54) < 2) {
        *(s32 *)(state + 0x54) = 1000;
        *(f32 *)(state + 0x50) = (f32) * (s32 *)(state + 0x54);
    }
    *(u8 *)(state + 0x80) = 20;
    *(u8 *)(state + 0x82) = 14;
    *(f32 *)(state + 0x64) = 0.5f;
    *(u8 *)(state + 0x86) = 0;
    func_00473A88((Obj *)object, 1, -1);
    return 1;
}
