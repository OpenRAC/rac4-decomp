#include "common.h"
/* Ported from rac3-decomp's func_0013D080 (src/boot_elf/core/13C8D0.c, GPL-3.0), the same code in both games. */

extern s32 func_00158A30(s32, s32, void *);
s32 func_00159718(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_00158A30(0x3B, 0x18, buf);
}
