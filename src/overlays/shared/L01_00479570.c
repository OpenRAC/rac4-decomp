#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));
extern void *func_L01_00479178(u8 *object, Quadword unused, Quadword position);

void *func_L01_00479570(u8 *object, const Quadword *position)
{
    return func_L01_00479178(object, *(const Quadword *)(object + 0xC0), *position);
}
