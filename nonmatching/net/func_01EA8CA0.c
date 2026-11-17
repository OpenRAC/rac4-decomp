/* Not matching yet: BYTES 29/80 (tools/try_func.py func_01EA8CA0 --diff). Not part of the build. */
#include "common.h"

typedef struct { s32 lo; s32 hi; } Pair;

extern s32 func_01EA79F8(s32, s32 *, Pair, s32);
extern s32 D_1B23B0[];

s32 func_01EA8CA0(s32 *arg0, Pair arg1, s32 arg2) {
    *arg0 = 0;
    if (D_1B23B0[0] == 0) {
        return 5;
    }
    return func_01EA79F8(D_1B23B0[1], arg0, arg1, arg2);
}
