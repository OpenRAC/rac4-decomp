#include "common.h"
/* Set the object's selected flag field when its resource is enabled. */
void func_0047F490(char *p, int a)
{
    unsigned char *q = *(unsigned char **)(p + 0x24);
    if (q && q[0xB]) {
        unsigned int v = (*(unsigned short *)(p + 0x36) | 0x8000) & 0x87FF;
        *(unsigned short *)(p + 0x36) = v;
        if (a == 10)
            *(unsigned short *)(p + 0x36) = v | 0x5000;
        else
            *(unsigned short *)(p + 0x36) = v | (a << 11);
    }
}
