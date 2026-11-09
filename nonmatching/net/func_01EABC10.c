/* Not matching yet: BYTES 13/88 (tools/try_func.py func_01EABC10 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"
extern s32 func_01EAB210(u32 *);
extern u32 D_00168BA4[],D_00168BA8[];
/* A successful query writes a u32 sample; retail has no fallback for an unwritten sample on error. */
s32 func_01EABC10(u32 *out)
{
 u32 now, delta, result;
 u32 *previous, *total;
 s32 status = func_01EAB210(&now);
 previous=D_00168BA4; total=D_00168BA8;
 delta=now-*previous;
 result=*total+delta;
 *previous=now; *total=result; *out=result;
 return status;
}
