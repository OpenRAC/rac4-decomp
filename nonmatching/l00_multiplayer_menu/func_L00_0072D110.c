/* Not matching yet: BYTES 39/48 (tools/try_func.py func_L00_0072D110 --diff). Not part of the build. */
#include "common.h"

extern u32 D_173824;

// True when bit `index` of the D_173824 bitfield is set.
s32 func_L00_0072D110(s32 index) {
    u32 bits = D_173824;
    s32 r = 0;

    if ((u32)index < 0x14) {
        r = ((1 << index) & bits) != 0;
    }
    return r;
}
