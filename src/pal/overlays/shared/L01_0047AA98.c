#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));
extern void *func_L01_0047A6A0(u8 *object, Quadword unused, Quadword position);

void *func_L01_0047AA98(u8 *object, const Quadword *position)
{
    return func_L01_0047A6A0(object, *(const Quadword *)(object + 0xC0), *position);
}
