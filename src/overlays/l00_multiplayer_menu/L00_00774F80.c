#include "common.h"

extern void func_0011A9EC(void *, void *);
extern s32 func_0011AB04(u8 *);

/* walks five records: copies each from its slot unless it is already in place, then skips its string */
s32 func_L00_00774F80(u8 *base) {
    u8 *p = base + 4;
    s32 i = 0;
    s32 off = 4;
    u8 *q;
    s32 n;

    do {
        n = 4;
        q = (i > n) ? 0 : base + off;
        if (q != p) {
            func_0011A9EC(p, q);
        }
        i++;
        off += 0x18;
        n = func_0011AB04(p);
        p += n + 1;
    } while (i < 5);
    return p - base;
}
