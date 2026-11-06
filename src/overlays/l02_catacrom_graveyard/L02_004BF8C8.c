#include "common.h"

typedef struct Obj Obj;
extern void func_00473A88(Obj *object, u8 state, s32 type);

s32 func_L02_004BF8C8(u8 *object)
{
    u8 *state = *(u8 **)(object + 0xAC);
    if (*(u8 *)(object + 0x20) != 0)
        return 0;
    *(s32 *)(state + 0x58) = 8;
    *(f32 *)(state + 0x54) = 3.0f;
    *(u8 *)(state + 0x50) = 0;
    *(u8 *)(object + 0x30) = 0xFF;
    *(u16 *)(object + 0x36) |= 0x10;
    func_00473A88((Obj *)object, 1, -1);
    return 1;
}
