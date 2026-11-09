/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A370(void *,const void *,s32);
extern void func_01EADA78(void *,s32);
/* Copies through a local buffer and transforms it. */
void func_01EACFC0(void *out,const void *in,s32 x)
{
 char buf[0x200]; func_0011A370(buf,in,0x200); func_01EADA78(buf,x); func_0011A370(out,buf,0x200);
}
