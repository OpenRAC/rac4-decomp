#include "common.h"

typedef struct Obj Obj;
extern void func_00473A88(Obj *object, u8 state, s32 type);

void func_L01_004CA8A0(u8 *object)
{
    s32 current = *(u8 *)(object + 0x20);
    u8 *state = *(u8 **)(object + 0xAC);
    if (current == 0) {
        s32 count;
        *(u8 *)(object + 0x30) = 0xFF;
        *(s32 *)(state + 4) = 0;
        count = *(s32 *)(state + 0);
        if (count <= current)
            count = 1;
        *(s32 *)(state + 0) = count;
        func_00473A88((Obj *)object, 1, -1);
    }
}
