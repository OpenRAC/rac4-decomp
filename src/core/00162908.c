#include "common.h"

s32 D_0021E0AC = 0;
s32 *D_0021E0B0 = 0;

/* Returns the index of the first entry of the table at D_0021E0B0 (count D_0021E0AC) equal to arg0, or -1. */
s32 func_00162908(s32 arg0) {
    s32 result = -1;
    s32 i;

    for (i = 0; i < D_0021E0AC; i++) {
        if (arg0 == D_0021E0B0[i]) {
            result = i;
            break;
        }
    }
    return result;
}
