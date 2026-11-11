/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void *func_01EEDCD0(void *,const void *,s32),*func_0011A518(void *,s32,s32);
extern char D_0019D0E0[],D_0016E688[];
/* Initializes a record and buffer. */
void func_01EF83AC(u8 *p)
{
 func_01EEDCD0(p+0x38,D_0019D0E0,0x40); *(s32*)(p+0xb4)=1; *(s32*)(p+0xb8)=0; func_0011A518(p+0xbc,0,0x80); *(s32*)(p+0x13c)=1; *(s32*)(p+0x30)=-1; *(u32*)(p+0x2c)=0xff000000; *(void**)(p+0xa0)=D_0016E688; *(s32*)(p+0x140)=0; *(s32*)(p+0x16c)=0; *(s32*)(p+0x154)=0; *(s32*)(p+0x158)=0;
}
