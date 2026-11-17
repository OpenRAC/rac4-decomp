#include "common.h"

extern u8 D_001723B0[];
extern u8 *D_0021DFE8;

/* sets or clears a bit in a table entry when the id is found among ten slots */
s32 func_0015FE10(s32 a0, s32 a1, s32 a2, s32 *a3) {
    s32 i;
    u8 *t;
    u8 *p;

    p = D_0021DFE8;
    if (D_001723B0[0] != 0 && p != 0) {
        i = 0;
        t = p + 0x104;
        while (i < 10) {
            if (t[i] == a2) {
                s32 bit = 1 << a2;
                if (*a3 != 0) {
                    *(u16 *)(p + 0x1AC) |= bit;
                } else {
                    *(u16 *)(p + 0x1AC) &= ~bit;
                }
                break;
            }
            i++;
        }
    }
    return 4;
}
