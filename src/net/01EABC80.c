/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, s32);
extern char D_001B2420[], D_001B25B8[];
extern s32 D_00168BA4[], D_00168BA8[];
/* Clears global buffers and counters. */
s32 func_01EABC80(void)
{
    func_0011A518(D_001B2420,0,0x198);
    func_0011A518(D_001B25B8,0,8);
    D_00168BA4[0]=0;
    D_00168BA8[0]=0;
    return 0;
}
