#include "common.h"

extern u8 D_00171B40[];

/* Clear matching bytes in a four-entry slice of D_00171B40. */
void func_L01_004AF160(s32 arg0) {
    s32 i = 3;
    u8 *base = D_00171B40;
    u8 *p = base + 0x29;
    do {
        if (*p == arg0) {
            *p = 0;
        }
        i--;
        p++;
    } while (i >= 0);
}
