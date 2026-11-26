#include "common.h"

s32 D_2206C0 = 0;
s32 D_2206CC = 0;
s32 D_2206D8 = 0;
s32 D_2206C4 = 0;
s32 D_2206D0 = 0;
s32 D_2206DC = 0;
s32 D_2206C8 = 0;
s32 D_2206D4 = 0;
s32 D_2206E0 = 0;

/* Three-region bump allocator: align the offset, then try each region in turn. */
s32 func_004E4D38(s32 arg0, s32 arg1) {
    s32 mask = -arg1;
    s32 base;
    s32 off;
    u32 end;

    base = D_2206C0 + D_2206D8 - 1;
    off = (base + arg1) & mask;
    end = off + arg0;
    if (end < (u32)(D_2206C0 + D_2206CC)) {
        D_2206D8 = end - D_2206C0;
    } else {
        s32 base2;
        u32 end2;
        base2 = D_2206C4 + D_2206DC - 1;
        off = (base2 + arg1) & mask;
        end2 = off + arg0;
        if (end2 < (u32)(D_2206C4 + D_2206D0)) {
            D_2206DC = end2 - D_2206C4;
        } else {
            s32 base3;
            u32 end3;
            base3 = D_2206C8 + D_2206E0 - 1;
            off = (base3 + arg1) & mask;
            end3 = off + arg0;
            if (end3 < (u32)(D_2206C8 + D_2206D4)) {
                D_2206E0 = end3 - D_2206C8;
            }
        }
    }
    return off;
}
