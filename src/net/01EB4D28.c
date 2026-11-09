/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, s32);
/* Initializes and serializes a word. */
void func_01EB4D28(u8 *p, u32 x)
{
    func_0011A518(p,0,0x10);
    *(u32 *)p=0;
    p[7]=x;
    p[5]=x>>16;
    p[6]=x>>8;
    p[4]=x>>24;
}
