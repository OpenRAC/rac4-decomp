#include "common.h"

extern s32 func_0011AB04(u8 *);
extern s32 func_L00_005BDC90(s32 arg0, s32 arg1, f32 arg2);
extern s32 func_L00_007646A0(s32 arg0, f32 fparg0, s32 arg1);

/* Counts down from the func_0011AB04 result while the func_L00_005BDC90 sum stays above arg1; returns the index or 0. */
s32 func_L00_007646F0(s32 arg0, s32 arg1, s32 arg2, f32 fparg0)
{
    s32 temp_s2;
    s32 var_s0;

    var_s0 = func_0011AB04((u8 *)arg0);
    if (func_L00_007646A0(arg0, fparg0, arg1) != 0) {
        temp_s2 = func_L00_005BDC90(arg2, func_0011AB04((u8 *)arg2), fparg0);
        do {
            var_s0 -= 1;
        } while (arg1 < (func_L00_005BDC90(arg0, var_s0, fparg0) + temp_s2));
    }
    return (var_s0 > -1) ? var_s0 : 0;
}
