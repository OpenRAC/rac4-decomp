#include "common.h"

extern s32 func_L01_00571C50(u32 a0, u32 a1, s32 a2);
extern u16 D_24D120[];
extern u8 D_24F120[];

/* Store val at index idx of the u16 table D_24D120 and move the old entry into the 0x26 field of the 48-byte entry val in D_24F120; always returns 1. */
s32 func_L01_00571B40(u16 idx, u16 val)
{
    u16 old;
    u8 *e;

    if (idx < 0x1000 && val != 0x801) {
        if (func_L01_00571C50(idx, val, 0) == 0) {
            e = D_24F120 + val * 0x30;
            old = D_24D120[idx];
            D_24D120[idx] = val;
            *(u16 *)(e + 0x26) = old;
            return 1;
        }
        return 1;
    }
    return 1;
}
