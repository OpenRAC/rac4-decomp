/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void *func_01EEDCD0(void *, const void *, s32);
extern void *func_0011A518(void *, s32, s32);
extern char D_0019C5F0[];
/* Initializes a record and embedded buffer. */
void func_01EF262C(u8 *p)
{
 func_01EEDCD0(p+0x38,D_0019C5F0,0x40); *(s32*)(p+0xb4)=14; *(s32*)(p+0xb8)=0; *(s32*)(p+0xc0)=0; func_0011A518(p+0xc4,0,0x80); *(s32*)(p+0x144)=0; *(s32*)(p+0x2c)=-1; *(s32*)(p+0x30)=-256; *(s32*)(p+0xbc)=-1;
}
