/* cflags: @ee296 -O2 -G0 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern u32 D_173824;

// True when bit `index` of the D_173824 bitfield is set (the index is a1: the
// first parameter is unused).
s32 func_L00_0072D110(s32 arg0, s32 index) {
    u32 bits = D_173824;
    s32 r = 0;

    if ((u32)index < 0x14) {
        r = (bits & (1 << index)) != 0;
    }
    return r;
}
