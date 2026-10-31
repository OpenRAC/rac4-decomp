#include "common.h"

extern s32 func_00453EF0(s32, s32);
extern s32 D_221478;

/* Return the entry at index arg1 of the table (offset 0x80 per entry) passed through func_00453EF0, or 0 when arg1 is -1. */
s32 func_00472518(s32 arg0, s32 arg1) {
    if (arg1 == -1) {
        return 0;
    }
    return func_00453EF0(D_221478 + (arg1 << 7), arg0);
}
