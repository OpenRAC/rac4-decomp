/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

extern void *func_01EEDCD0(void *,const void *,s32);
extern void *func_0011A518(void *,s32,s32);
extern char D_0019D1B0[],D_0019D1C0[];
/* Initializes a record and its embedded buffers. */
void func_01EF8CB4(u8 *p)
{
 func_01EEDCD0(p+0x38,D_0019D1B0,0x40); func_0011A518(p+0xb4,0,0x80); *(s32*)(p+0x30)=-1; *(u32*)(p+0x2c)=0xff000000; *(s32*)(p+0x16c)=-1; *(s32*)(p+0x15c)=0; *(s32*)(p+0x160)=0; func_01EEDCD0(p+0x134,D_0019D1C0,0x20);
}
