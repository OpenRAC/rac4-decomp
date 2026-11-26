/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s64 func_0012FE48(s64, s64);
extern s64 func_0012FEB0(s64, s64);
extern s64 func_00130480(s64, s64);

s64 func_L00_00546D70(s64 arg0) {
    s64 temp_s0;
    s64 temp_v0;
    s64 temp_v1;
    s64 var_s1;
    s64 var_s2;
    s64 var_s3;
    s64 var_s5;
    s32 var_s6;

    var_s3 = 0;
    var_s2 = arg0;
    var_s5 = 1;
    var_s6 = -1;
    var_s1 = func_00130480(0 - arg0, arg0);
    if (var_s1 != 0) {
        do {
            var_s6 = -var_s6;
            temp_s0 = func_0012FEB0(var_s2, var_s1);
            temp_v1 = func_00130480(var_s2, var_s1);
            var_s2 = var_s1;
            temp_v0 = func_0012FE48(temp_s0, var_s5) + var_s3;
            var_s3 = var_s5;
            var_s5 = temp_v0;
            var_s1 = temp_v1;
        } while (var_s1 != 0);
    }
    var_s3 = (var_s6 <= -1) ? (arg0 - var_s3) : var_s3;
    if (var_s2 == 1) {
        return func_00130480(var_s3, arg0);
    }
    return 0;
}
