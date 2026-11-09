/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01E9B788(void *,s32,void *,s32,s32);
/* Reads a value using the requested command. */
s32 func_01E9C170(void *a,s32 *p)
{
    if(func_01E9B788(a,31,p,0,4)<0) return -0x21e;
    return *p;
}
