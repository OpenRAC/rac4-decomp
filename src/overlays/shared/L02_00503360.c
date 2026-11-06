/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

void func_L02_00503360(s32 arg0, s32 arg1, void *arg2, f32 fparg0, f32 fparg1) {
    s32 var_5;
    void *var_6;
    var_5 = arg1;
    var_6 = arg2;
    if (var_5 > 0) {
        do {
            var_5 = var_5 - 1;
            *(f32 *)((u8 *)var_6 + 0) = (f32)(*(f32 *)((u8 *)var_6 + 0) + fparg0);
            *(f32 *)((u8 *)var_6 + 4) = (f32)(*(f32 *)((u8 *)var_6 + 4) + fparg1);
            var_6 = (void *)((unsigned char *)var_6 + 8);
        } while (var_5 != 0);
    }
}
