#include "common.h"

extern void func_004257D0(void *);
extern void func_00424800(void *, float);
/* Compute the blend amount and update the object. */
void func_00424908(char *p)
{
    char *s = *(char **)(p + 0xAC);
    float a = 1.0f - (float)(*(int *)(s + 0x54) - 90) / 10.0f;
    func_004257D0(p);
    func_00424800(p, a);
}
