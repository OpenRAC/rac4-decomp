/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_00517808(void);

// Adds a signed seconds/nanoseconds offset to a time value, with carry, storing into the destination.
s32 func_L00_0052D158(u8 *dst, u8 *src, s32 nsec, s32 sec) {
    s32 result = 0;
    s32 carry = 0;
    u8 *g = func_00517808();
    if (dst == 0) {
        result = 0x2721;
    } else {
        u8 *a = src == 0 ? g + 0x230 : src + 8;
        u8 *d = dst + 8;
        s32 n = *(s32 *)(a + 0) > -1 ? nsec : -nsec;
        s32 adj = sec;
        u32 lo;
        if (n < 0) {
            u32 old = *(u32 *)(a + 8);
            if (old < (u32)-n) {
                u32 t = n + 0x3B9ACA00;
                adj -= 1;
                *(u32 *)(d + 8) = old + t;
                goto join;
            }
        }
        lo = *(u32 *)(a + 8) + n;
        *(u32 *)(d + 8) = lo;
        if (lo > 0x3B9AC9FF) {
            adj = sec + 1;
            *(u32 *)(d + 8) = lo + 0xC4653600;
        }
    join:
        {
            u32 hi = *(u32 *)(a + 4);
            u32 s = hi + adj;
            *(u32 *)(d + 4) = s;
            if (adj > 0 && s < hi) {
                carry = 1;
            } else if (adj < 0) {
                carry = hi >= *(u32 *)(d + 4) ? 0 : -1;
            }
            *(s32 *)(d + 0) = *(s32 *)(a + 0) + carry;
        }
    }
    return result;
}
