#include "common.h"

typedef struct Obj Obj;
extern void func_00473A88(Obj *object, u8 state, s32 type);

void func_L41_00449C88(Obj *object)
{
    u8 *bytes = (u8 *)object;
    u8 *state = *(u8 **)(bytes + 0xAC);
    u32 flags;

    if (state == 0)
        return;
    if ((u32)(bytes[0x20] - 3) < 2) {
        *(s32 *)(state + 0x10) = -1;
        *(s32 *)(state + 0x1C) = 10;
        *(s32 *)(state + 0x3C) = 0;
    }
    flags = *(u16 *)(bytes + 0x34);
    if (flags & 1) {
        u8 current = bytes[0x20];
        *(u16 *)(bytes + 0x34) = flags & 0xFFBE;
        if (current != 1)
            func_00473A88(object, 1, -1);
    }
}
