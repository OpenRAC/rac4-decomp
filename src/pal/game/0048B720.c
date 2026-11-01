#include "common.h"

extern char *func_004546C8(int);
/* Apply the capped gain to the selected resource. */
void func_0048B720(void *unused, char *p)
{
    int a = (int)(*(float *)(p + 0x20) * *(float *)(p + 0x24) * 1024.0f);
    char *s;
    if (a > 1024)
        a = 1024;
    s = func_004546C8(*(short *)(p + 0xC));
    if (s)
        *(short *)(s + 0xC) = a;
}
