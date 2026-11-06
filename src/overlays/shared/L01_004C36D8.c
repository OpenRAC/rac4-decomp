#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));
extern void func_L01_005A8A28(u8 *object);

void func_L01_004C36D8(u8 *object)
{
    u8 *state = *(u8 **)(object + 0xAC);
    *(Quadword *)(state + 0x4C0) = *(const Quadword *)(object + 0x10);
    func_L01_005A8A28(object);
    *(s32 *)(state + 0x334) = 0;
    *(s32 *)(state + 0x33C) = 3;
}
