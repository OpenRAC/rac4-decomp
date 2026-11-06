#include "common.h"

/* Defined in this file: retail reaches it through $gp outside a delay slot,
   which ps2eeas only does for data defined above (tools/ps2eeas_sdata.py). */
s32 D_00221FF8 = 0;

// Set element in array via gp-relative address
void func_L00_00591410(s32 arg0) {
    s32 *ptr = (s32 *)&D_00221FF8 + arg0;
    *ptr = 1;
}

s32 func_L00_00591428(s32 index)
{
    return *(s32 *)((u32)&D_00221FF8 + ((u32)index << 2));
}
