#include "common.h"

struct Obj;
extern void func_00473A88(struct Obj *object, u8 state, s32 type);

s32 func_L01_00491730(u8 *object)
{
    s32 result;
    u8 *state = *(u8 **)(object + 0xAC);

    if (object[0x20] == 0) {
        object[0x30] = 0xFF;
        *(u32 *)(state + 0x48) = 0;
        func_00473A88((struct Obj *)object, 1, -1);
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
