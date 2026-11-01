#include "common.h"

// Scales successive source elements by successive powers of the multiplier.
void func_0014ADD8(f32 *arg0, f32 *arg1, u32 arg2, f32 fparg0) {
    f32 factor = 1.0f;
    if ((s32)arg2 >= 0) {
        arg2++;
        do {
            f32 value = *arg0++ * factor;
            factor *= fparg0;
            *arg1++ = value;
        } while (--arg2 != 0);
    }
}
