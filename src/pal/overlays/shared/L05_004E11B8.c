#include "common.h"

struct Obj;
extern void func_00473A88(struct Obj *object, u8 state, s32 type);

s32 func_L05_004E11B8(u8 *object, s64 binding)
{
    u8 *state = *(u8 **)(object + 0xAC);
    u8 current;

    if ((s64) * (s32 *)(state + 0x144) != binding) {
        return 0;
    }
    current = object[0x20];
    if (current == 3 || current == 6) {
        func_00473A88((struct Obj *)object, 7, -1);
    } else if (current == 2) {
        func_00473A88((struct Obj *)object, 1, -1);
    }
    *(s32 *)(state + 0x144) = 0;
    return 1;
}
