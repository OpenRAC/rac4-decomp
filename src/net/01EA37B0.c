/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *,s32,s32);
/* Initializes a nonnull record. */
s32 func_01EA37B0(s32 address)
{
 s32 *p=(s32 *)address; s32 r=0x17; if(p){func_0011A518(p,0,0x20); p[0]=1; r=0;} return r;
}
