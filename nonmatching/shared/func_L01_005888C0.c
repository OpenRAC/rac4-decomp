/* Not matching yet: BYTES 22/56; mask coalesces to dying $a0, index stuck in $a2 (tools/try_func.py func_L01_005888C0 --diff). Not part of the build. */
/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern s32 D_222D14;

/* Write the masked id and the delta-tagged time word into the pair of shorts. */
s32 func_L01_005888C0(s32 a0, u16 *a1, s32 a2, s32 a3, char *t0, char *t1)
{
    s32 base = D_222D14;
    s32 v = a0 & 0x7FFF;
    s32 idx = a2 + 1;
    s32 delta;
    s32 off;
    s32 d;
    u16 *p;
    s32 tag;
    s32 r;

    *(u16 *)a1 = v;
    delta = t0 - (char *)base;
    off = idx << 1;
    d = delta >> 8;
    p = (u16 *)(t1 + off);
    tag = d | 0x8000;
    r = 1;
    *p = tag;
    *(u8 *)(t0 + 0x21) = a3;
    return r;
}
