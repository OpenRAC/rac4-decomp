#include "common.h"

extern s32 func_00505B20(void);
extern u8 D_003D9370[];
extern u8 D_30A160[];

typedef void (*fn_004B8B20)(u32, void *, s32);

/* Dispatches into a 0x14-byte record table: D_30A160[func_00505B20()].f4 selects the
   record in D_003D9370, whose f10 is called with -1 or 1 depending on arg0. */
void func_004B8B20(s32 arg0)
{
    u8 *base;
    s32 *entry;

    base = D_30A160 + (func_00505B20() << 4);
    entry = (s32 *)(D_003D9370 - (-(((s32 *)base)[1] * 0x14)));
    ((fn_004B8B20)entry[4])((arg0 != 0) ? 0xFFFFFFFFu : 1, entry, 0x14);
}
