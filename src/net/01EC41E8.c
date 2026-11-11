/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, s32);
/* Initializes network defaults. */
void func_01EC41E8(u8 *p)
{
    func_0011A518(p,0,0x58);
    *(s32*)p=0;
    *(s32*)(p+0x14)=0x275b;
    *(s32*)(p+0x28)=0x8000;
    *(s32*)(p+0x24)=0x8000;
    *(s32*)(p+0x1c)=0x3a98;
    *(s32*)(p+0x20)=30;
    p[0x34]=14;
    p[0x35]=1;
}
