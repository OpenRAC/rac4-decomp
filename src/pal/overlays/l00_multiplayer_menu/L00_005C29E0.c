#include "common.h"

extern s32 func_0011AB04(s8 *);
extern void func_L00_005C2000(void);
extern s32 func_L00_005C24C0(u8);

// text conversion
void func_L00_005C29E0(u8 *dst, s8 *src, s32 max) {
    s32 i;
    s32 j;
    s32 n;
    s32 len;
    s32 w;
    u8 lo;
    u8 hi;

    i = 0;
    len = func_0011AB04(src);
    n = (len < max) ? len : max;
    func_L00_005C2000();
    for (j = 0; j < n; j++) {
        if (*src >= 0) {
            if (i < max) {
                dst[i++] = *(u8 *)src;
            }
        } else {
            w = func_L00_005C24C0(*(u8 *)src);
            lo = w;
            hi = w >> 8;
            if (i < max) {
                dst[i++] = hi;
                if (i < max) {
                    dst[i++] = lo;
                }
            }
        }
        src++;
    }
    if (i < max) {
        dst[i] = 0;
    }
}
