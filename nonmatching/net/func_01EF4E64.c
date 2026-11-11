/* Not matching yet: BYTES 8/76 (tools/try_func.py func_01EF4E64 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"
extern void func_01EF58AC(void *,s32),func_01EF588C(void *,s32);
extern char D_0016FFB8[],D_00170010[];
/* Initializes dispatch pointers and state. */
void func_01EF4E64(u8 *p,s32 a)
{
 func_01EF58AC(p,a); *(void**)(p+8)=D_0016FFB8; *(void**)(p+0x80)=D_00170010; func_01EF588C(p,1); *(s32*)(p+0xc)=0;
}
