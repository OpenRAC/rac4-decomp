#include "common.h"

/* Finds the first maximal element, then stores its index and value. */
void func_00147D88(f32 *arg0, s32 arg1, s32 *arg2, f32 *arg3) {
    f32 cur;
    f32 best;
    s32 idx;
    s32 i;

    best = *arg0++;
    idx = 0;
    i = 1;
    while (i < arg1) {
        cur = *arg0++;
        if (best < cur) {
            best = cur;
            idx = i;
        }
        i++;
    }
    *arg2 = idx;
    *arg3 = best;
}
