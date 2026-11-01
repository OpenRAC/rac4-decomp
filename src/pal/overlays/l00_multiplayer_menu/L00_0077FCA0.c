/* cflags: -O2 -G8 */
#include "common.h"

// Clamps the value while retaining the original order of float comparisons.
f32 func_L00_0077FCA0(f32 value, f32 lower, f32 upper)
{
    f32 result = upper;

    if (value < lower) {
        goto below_lower;
    }
    if (result < value) {
        goto done;
    }
    return value;
below_lower:
    result = lower;
done:
    return result;
}
