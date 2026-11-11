/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void *func_01EEDCD0(void *,const void *,s32);
extern char D_0019E720[],D_0016E688[];
/* Initializes a network record. */
void func_01F0BBF8(u8 *p)
{
 func_01EEDCD0(p+0x38,D_0019E720,0x40); *(s32*)(p+0xb4)=14; *(s32*)(p+0x30)=-256; *(s32*)(p+0x2c)=-1; *(void**)(p+0xa0)=D_0016E688; *(s32*)(p+0xb8)=0; *(s32*)(p+0xbc)=0; *(s32*)(p+0x10)=0; *(s32*)(p+0xc0)=0;
}
