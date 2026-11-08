#include "common.h"

extern u32 *D_00222EE0;
extern void func_004E7990(s32, unsigned long, s32);

/* from rac3-decomp's func_00392C48 */
void func_L00_005C5278(s32 x, s32 y) {
    s32 n = x / 32;
    unsigned long *p, *q, *r;
    s32 i, a, b, lo, hi;
    func_004E7990(0x42, (0x8000UL << 24) | 0x4A, 0);
    D_00222EE0[0] = (n + 5) | 0x10000000;
    D_00222EE0[1] = 0;
    D_00222EE0[2] = 0;
    D_00222EE0[3] = (n + 5) | 0x50000000;
    p = (unsigned long *)D_00222EE0;
    r = p + 2;
    D_00222EE0 = (u32 *)r;
    p[2] = (0x8000UL << 45) | 1;
    r[1] = 0xE;
    r[2] = 0x32003;
    r[3] = 0x47;
    r[4] = (0x9000UL << 46) | 1;
    r[5] = 0x10;
    r[6] = 0x146;
    r[7] = (0x8000UL << 16) | 0x8080;
    r[8] = n | 0x8000 | (0x9000UL << 46);
    r[9] = 0x44;
    i = 0;
    if (n > i) {
        unsigned long t0, t1;
        a = y * 8;
        t0 = (unsigned long)(0x8000 - a) << 16;
        t1 = (unsigned long)(a + 0x7FF0) << 16;
        b = -(x * 8);
        lo = b + 0x8000;
        hi = b + 0x8200;
        q = p + 12;
        do {
            *q++ = lo | t0;
            *q++ = hi | t1;
            hi += 0x200;
            lo += 0x200;
            i++;
        } while (i < n);
    }
    D_00222EE0 += n * 4 + 0x14;
}
