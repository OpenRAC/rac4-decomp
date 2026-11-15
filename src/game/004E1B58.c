#include "common.h"

extern u8 D_1D2200[];
extern u8 *D_3367B8[];

/* Searches the D_3367B8 slots for arg0 and counts the nonzero flags at D_1D2200 + 0x2D0 in 0x80-byte steps. */
s32 func_004E1B58(s32 arg0) {
    s32 count;
    s32 i;
    s32 limit;
    u8 *q;
    u8 *base;
    u8 *p;

    limit = 0x2A;
    if (arg0 != 0) {
        i = 0;
        p = D_3367B8[0];
        while (p == 0 || *(s32 *)(p + 0x2EF0) != arg0 || p[0x266D] == 0) {
            i++;
            p = D_3367B8[i];
            if (i >= 0xA) {
                goto done;
            }
        }
        limit = 0x34;
    }
done:
    count = 0;
    if (limit != 0) {
        base = D_1D2200;
        if (base[0x2D0] != 0) {
            q = base + 0x2D0;
            do {
                count++;
                if (count >= limit) {
                    break;
                }
                q += 0x80;
            } while (*q != 0);
        }
    }
    return ((count ^ limit) != 0) ? count : -1;
}
