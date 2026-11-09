#include "common.h"

typedef int u128 __attribute__((mode(TI)));

s32 func_00474198(u128 arg0, u128 arg1, u128 arg2, u128 arg3, f32 *out);

extern u128 *D_0026F640[];

f32 func_0048B470(u128 arg0, u128 arg1, s32 arg2, s64 arg3) {
    f32 result;
    u128 *poly;
    s32 i;

    poly = D_0026F640[arg2];
    for (i = 1; i < *(s32 *)poly; i++) {
        if (func_00474198(arg0, arg1, poly[i], poly[i + 1], &result)) {
            return result;
        }
    }
    if (arg3 != 0) {
        if (func_00474198(arg0, arg1, poly[*(s32 *)poly], poly[1], &result)) {
            return result;
        }
    }
    return -1.0f;
}
