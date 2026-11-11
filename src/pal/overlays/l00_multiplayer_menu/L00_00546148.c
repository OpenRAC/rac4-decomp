/* cflags: @ee296 -O2 -G0 */
#include "common.h"

u32 func_L00_00546148(s32 value) {
    u32 out;
    s32 top;
    s32 nib;
    s32 high;
    s32 i;

    out = 0;
    top = value >> 28;
    nib = 0xF;
    nib = top & nib;
    if ((top & 7) != 0) {
        high = nib - (nib & 8);
    } else {
        high = 5;
    }
    for (i = 0; i < 7; i++) {
        out |= ((value >> (i * 4)) & 7) << (i * 4);
    }
    return (out & 0xFFFFFFF) | (high << 28);
}
