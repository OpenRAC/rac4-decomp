#include "common.h"

extern void func_00146F80(s32 arg0, s32 arg1, s32 arg2);

// Splits the float array at arg0 into the arg3 and arg4 arrays, zero-fills the remaining tails, then calls func_00146F80.
void func_00146E68(f32 *arg0, s32 arg1, s32 arg2, f32 *arg3, f32 *arg4) {
    s32 quarter = arg1 >> 2;
    s32 half = arg1 >> 1;
    s32 bit = 1 << arg2;
    f32 *a = arg3 + (0x100 - quarter);
    f32 *b = arg4 + (0x100 - quarter);
    s32 i;

    for (i = 0; i < quarter; i++) {
        *a++ = *arg0++;
        *b++ = *arg0++;
    }
    a = arg3;
    b = arg4;
    for (i = 0; i < (arg1 - quarter * 2) >> 1; i++) {
        *a++ = *arg0++;
        *b++ = *arg0++;
    }
    if (arg1 != half * 2) {
        i++;
        *a++ = *arg0;
        *b++ = 0.0f;
    }
    for (; i < 0x100 - quarter; i++) {
        *a++ = 0.0f;
        *b++ = 0.0f;
    }
    func_00146F80((s32)arg3, (s32)arg4, bit);
}
