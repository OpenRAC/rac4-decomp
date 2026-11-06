#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));

Quadword func_L01_004AB418(const u8 *object)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    const u8 *source = *(const u8 *const *)(state + 0x6C0);

    return *(const Quadword *)(source + 0x10);
}
