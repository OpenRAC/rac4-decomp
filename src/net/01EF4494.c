/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern double func_00130E90(double, double);
extern s32 func_001314C0(double);

// Compares the two values: returns 1 when the first is less than the second, each reduced through an 8.0 bias.
s32 func_01EF4494(double arg0, double arg1) {
    s32 temp_s2;
    double temp_s0;
    double temp_s1;

    temp_s0 = 8.0;
    temp_s1 = arg1;
    temp_s2 = func_001314C0(func_00130E90(arg0, temp_s0));
    return temp_s2 < func_001314C0(func_00130E90(temp_s1, temp_s0));
}
