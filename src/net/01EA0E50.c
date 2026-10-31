#include "common.h"

/* Expands arg2 bytes of 0x20-step word groups from arg1 into arg0, four bytes per word; returns 0. */
s32 func_01EA0E50(u8 *arg0, u32 *arg1, u32 arg2) {
    u32 i;
    u8 *dst;
    u32 *src;

    i = 0;
    if (arg2 != 0) {
        dst = arg0;
        src = arg1;
        do {
            i += 0x20;
            dst[0] = ((u8 *)src)[0];
            dst[1] = ((u8 *)src)[1];
            dst[2] = (*src & 0xFF0000) >> 16;
            dst[3] = (*src & 0xFF000000) >> 24;
            src++;
            dst += 4;
        } while (i < arg2);
    }
    return 0;
}
