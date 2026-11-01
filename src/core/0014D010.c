/* cflags: @ee29-01 -O2 -G0 -Wa,-G0 */
#include "common.h"

// Computes a scaled reciprocal and caps it at the supplied limit.
s32 func_0014D010(s32 arg0, f32 fparg0) {
    s32 value = (s32)(((512.0f / fparg0) * 3.9f) + 0.5f);
    if (arg0 < value) {
        value = arg0;
    }
    return value;
}
