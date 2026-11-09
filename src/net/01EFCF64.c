/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0011AB04(const char *);
extern s32 func_01EFCE48(char *,s32);
extern void *func_0011A41C(void *,const void *,s32);
/* Moves a suffix and terminates the resulting string. */
s32 func_01EFCF64(char *p,s32 n)
{
 s32 a=func_0011AB04(p), b=func_01EFCE48(p,n); func_0011A41C(p+n,p+b,a-b); p[n+a-b]=0; return n;
}
