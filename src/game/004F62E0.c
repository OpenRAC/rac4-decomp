#include "common.h"
/* Update the object flag after clearing supported object kinds. */
void func_004F62E0(char *p)
{
    int a = 0;
    int k = *(short *)(p + 0xBC);
    if (k == 0x216A || k == 0x2567) {
        *(int *)(p + 0xA8) = 0;
        a = 1;
    }
    if (a)
        *(unsigned short *)(p + 0x34) &= ~2;
    else
        *(unsigned short *)(p + 0x34) |= 2;
}
