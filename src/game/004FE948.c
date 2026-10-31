#include "common.h"

// Step arg1 by (arg3 - arg2 + 1) up to the range [arg2, arg3], then down while above arg3.
s32 func_004FE948(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 step = arg3 - arg2 + 1;
    s32 x = arg1;
    if (x < arg2) {
        x += step;
        while (x < arg2) {
            x += step;
        }
    }
    while (arg3 < x) {
        x -= step;
    }
    return x;
}
