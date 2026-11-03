#include "common.h"
void func_00526848(char *p)
{
    float v;
    if (*(int *)(p + 0x1AE0) == 1) {
        *(float *)(p + 0x1AFC) = 2.0f;
        return;
    }
    if (((*(int *)(p + 0x25CC) == 4 || *(int *)(p + 0x25CC) == 21) && *(int *)(p + 0x1AE0) == 2) || *(unsigned char *)(p + 0x2ECD))
        v = 0.6f;
    else
        v = 1.15f;
    *(float *)(p + 0x1AFC) = v;
    if (*(int *)(p + 0x25D4) == 3)
        *(float *)(p + 0x1AFC) = 1.75f;
}
