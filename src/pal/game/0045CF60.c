#include "common.h"

extern void *func_0011A518(void *, s32, s32);
/* Initialize the object and fill its payload with the default byte. */
void func_0045CF60(char *p)
{
    *(s32 *)(p + 0x58) = 0;
    *(s32 *)(p + 0x5c) = 0;
    *(s32 *)(p + 0x60) = 0;
    func_0011A518(p + 8, 0xcd, 0x50);
    *(s32 *)(p + 0x68) = 1;
    p[0x6c] = 0;
}
