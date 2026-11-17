#include "common.h"

extern s32 func_004F2520(void);
extern s32 func_004F2528(void);
extern unsigned int D_00171C08[];
s32 D_00220980 = 0;

/* Checks a bit in D_00171C08 for (arg0, arg1) pair; on a free bit, records arg2 and returns 1. */
s32 func_004F50D8(s32 arg0, s32 arg1, u32 arg2) {
    u32 var_v1;

    if ((arg0 == -1) || (func_004F2528() == arg0)) {
        if (arg1 != -1) {
            if (func_004F2520() != arg1) {
                return 0;
            }
        }
        var_v1 = arg2 >> 5;
        if (D_00171C08[var_v1] & (1 << (arg2 & 0x1F))) {
            return 0;
        }
        D_00220980 = arg2;
        return 1;
    }
    return 0;
}
