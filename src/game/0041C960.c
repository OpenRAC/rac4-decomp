#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));

extern void func_0041C7E8(void *object, Quadword position, s32 count,
                          f32 radius, f32 speed, f32 spread);

void func_0041C960(char *object)
{
    char *state = *(char **)(object + 0xAC);

    func_0041C7E8(object, *(Quadword *)(state + 0x40), 1,
                  1.2f, 0.3f, 0.5f);
}
