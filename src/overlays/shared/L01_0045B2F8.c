#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));
extern s32 func_L01_0045C038(const u8 *object);

Quadword func_L01_0045B2F8(const u8 *object)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    if (func_L01_0045C038(object) != 0 && object[0x20] == 0x15)
        return *(const Quadword *)(state + 0x5B0);
    if (*(const s32 *)(state + 0x320) != 0)
        return *(const Quadword *)(state + 0x310);
    return *(const Quadword *)(state + 0x5D0);
}
