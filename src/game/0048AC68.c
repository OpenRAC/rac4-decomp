#include "common.h"

extern char *func_00453EB0(int);
/* Apply the capped gain to the selected resource. */
void func_0048AC68(void *unused, char *p)
{
    int a = (int)(*(float *)(p + 0x20) * *(float *)(p + 0x24) * 1024.0f);
    char *s;
    if (a > 1024)
        a = 1024;
    s = func_00453EB0(*(short *)(p + 0xC));
    if (s)
        *(short *)(s + 0xC) = a;
}
