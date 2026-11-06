#include "common.h"

typedef struct Obj Obj;
extern void func_00473A88(Obj *object, u8 state, s32 type);

void func_L01_00458058(Obj *object)
{
    u8 *bytes = (u8 *)object;
    u32 flags = *(u16 *)(bytes + 0x34);
    u8 *definition = *(u8 **)(bytes + 0x24);
    u32 render;

    flags &= 0xFFBE;
    *(u16 *)(bytes + 0x34) = flags;
    flags |= *(u16 *)(definition + 0x44) & 0x1000;
    *(u16 *)(bytes + 0x34) = flags;
    flags &= 0xFFFD;
    render = *(u32 *)(definition + 0x10);
    *(u16 *)(bytes + 0x34) = flags;
    *(u32 *)(bytes + 0x98) = render;
    *(u32 *)(bytes + 0x98) = *(u32 *)(definition + 0x10);
    func_00473A88(object, 2, -1);
}
