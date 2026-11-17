/* cflags: -mcheck-zero-division */
#include "common.h"

extern u16 D_004AE7F8[];

// Returns a month-table entry for the year, with leap-year adjustment, plus arg2.
s32 func_L00_005288D8(s32 arg0, s32 arg1, s32 arg2) {
    u8 *tbl = (u8 *)D_004AE7F8;
    s32 leap = 0;
    arg1 = arg1 * 2;
    if (!(arg0 & 3)) {
        if ((arg0 % 100) != 0 || (arg0 % 400) == 0) leap = 1;
    }
    return *(u16 *)(tbl + (leap * 0x1A + arg1)) + arg2;
}
