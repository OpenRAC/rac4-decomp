#include "common.h"

extern s32 D_00165D48_[];
#define D_00165D48 (D_00165D48_[0])
extern s32 D_00165D4C_[];
#define D_00165D4C (D_00165D4C_[0])
extern s32 D_1ACE08_[];
#define D_1ACE08 (D_1ACE08_[0])

// Clears the first word of one 16-byte entry of a table: the table at D_00165D48 (count D_00165D4C) for a non-negative index, or the table at D_1ACE08 (32 entries) for a negative one; returns -0x69 when the index is out of range.
s32 func_0012ED28(s32 arg0) {
    s32 *base;
    u32 limit;
    s32 idx;

    idx = arg0;
    if (arg0 < 0) {
        base = &D_1ACE08;
        idx = arg0 & 0x7FFFFFFF;
        limit = 0x20;
    } else {
        base = (s32 *)D_00165D48;
        limit = D_00165D4C;
    }
    if ((u32)idx < limit) {
        *(s32 *)((idx << 4) + (u32)base) = 0;
        return 0;
    }
    return -0x69;
}
