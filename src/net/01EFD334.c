/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_01EFB828(void *,s32,s32,s32,s32);
extern void func_01EFB8A8(void *,s32,s32,s32);
extern char D_00170678[];
/* Initializes a record through two helpers. */
s32 func_01EFD334(u8 *p,s32 a,s32 b,s32 c)
{
 func_01EFB828(p,a,b,c,1); *(void**)(p+0xb0)=D_00170678; func_01EFB8A8(p,a,b,c); *(s32*)(p+0x2b8)=1; return 1;
}
