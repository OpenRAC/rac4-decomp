/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern void func_L01_00436928(void *);
extern void func_L00_00582A90(void *, float);
/* Compute the blend amount and update the object. */
void func_L01_00435C00(char *p)
{
    char *s = *(char **)(p + 0xAC);
    float a = 1.0f - (float)(*(int *)(s + 20) - 90) / 10.0f;
    func_L01_00436928(p);
    func_L00_00582A90(p, a);
}
