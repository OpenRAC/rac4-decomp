#include "common.h"

// Copies a buffer four bytes at a time, byte by byte, in ascending order; arg2 is a byte count rounded up to whole words.
void func_01EB1A80(u8 *arg0, u8 *arg1, u32 arg2) {
    u32 i;
    u8 *d;
    u8 *s;
    u32 w;
    u16 h;

    i = 0;
    if (arg2 != 0) {
        d = arg0;
        s = arg1;
        do {
            i += 4;
            d[0] = s[0];
            w = *(u32 *)s;
            d[1] = (u8)(w >> 8);
            h = *(u16 *)(s + 2);
            d[2] = (u8)h;
            d[3] = s[3];
            s += 4;
            d += 4;
        } while (i < arg2);
    }
}
