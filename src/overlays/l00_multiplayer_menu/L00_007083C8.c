#include "common.h"

/* Returns bit 0 of the halfword the callee writes (shifted right once) when the global at 0x172188 is not -1; otherwise 0. */
extern s32 func_00154F18(s32 arg0, s16 *arg1);
extern s32 D_00172188[];

s32 func_L00_007083C8(void) {
    s16 sp0;

    if (D_00172188[0] == -1) {
        return 0;
    }
    sp0 = 0;
    if (func_00154F18(D_00172188[0], &sp0) != 0) {
        return 0;
    }
    return ((u16)sp0 >> 1) & 1;
}
