/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/frontbin/3AA9D8.c func_003AACC0.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

typedef struct {
    f32 prefix[2];
    f32 first;
    f32 second;
} Curve;
extern f32 func_004EFE10(f32, f32, f32, f32, f32);
void func_004EFAD0(const Curve *curve, f32 *output, f32 factor)
{
    *output = func_004EFE10(factor, 0.0f, curve->first, curve->second, 1.0f);
}
