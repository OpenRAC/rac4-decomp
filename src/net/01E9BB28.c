/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01E9B788(void *,s32,void *,s32,s32);
/* Sends two words and reads a result. */
s32 func_01E9BB28(void *a,s32 *p,s32 x,s32 y)
{
    p[0]=x;
    p[1]=y;
    if(func_01E9B788(a,3,p,8,4)<0) return -0x21e;
    return *p;
}
