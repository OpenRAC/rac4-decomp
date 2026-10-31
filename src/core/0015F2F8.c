#include "common.h"

extern s32 D_00172184_[];
#define D_00172184 (D_00172184_[0])

/* Reduces arg2 into a range set by arg0 and the global at D_00172184; returns arg3 when arg1 is zero. */
s32 func_0015F2F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_a2 = arg2;

    if (arg1 != 0) {
        if ((u32)(arg0 - 2) < 3U) {
            if (arg2 >= D_00172184) {
                var_a2 = arg2 - D_00172184;
            } else {
                var_a2 = (arg2 <= -1) ? (D_00172184 + arg2) : arg2;
            }
        } else if (arg0 == 1) {
            var_a2 = ((u32)arg2 >= 4U) ? (arg2 & 3) : arg2;
        } else {
            var_a2 = ((u32)arg2 >= 2U) ? (arg2 & 1) : arg2;
        }
    } else {
        var_a2 = arg3;
    }
    return var_a2;
}
