/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0011D920(s8 *,s8 *,...);
extern void *func_0011AFC8(void *,const void *,s32);
extern char D_00197DF8[];
/* Formats and copies a terminated string. */
s32 func_01ED4380(char *out,s32 n)
{
 char buf[64]; func_0011D920((s8 *)buf,(s8 *)D_00197DF8,2,8,6); func_0011AFC8(out,buf,n); out[n-1]=0; return 0;
}
