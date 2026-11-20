/* Not matching yet: BYTES 0/528, exact only with inline asm (plzcw), which matched C may not use (tools/check_func.py func_004E7E58). Not part of the build. */
#include "common.h"

extern u32 *D_00221E20;

extern void func_00138E08(void *, s16, s16, s16, s32, s32, s16, s16);

/* plzcw (R5900 MMI): leading sign bits minus one, so 30 - n is floor(log2(x)) for x > 0. No C form
 * gives retail's bare plzcw: SN's __builtin_plzcw works on 128-bit values and adds por copies and a
 * sign extension. */
static inline s32 lead_sign_bits(s32 x)
{
    s32 r;
    __asm__("plzcw %0, %1" : "=r"(r) : "r"(x));
    return r;
}

u64 func_004E7E58(u8 *src, s32 tbp, s32 width, s32 height)
{
    s32 size;
    s32 log_w;
    s32 log_h;
    s32 chunk;
    s32 off;

    log_w = 30 - lead_sign_bits(width);
    log_h = 30 - lead_sign_bits(height);
    if (width & (width - 1)) {
        log_w++;
    }
    if (height & (height - 1)) {
        log_h++;
    }
    size = width * (height << 2);
    chunk = width << 7;
    size = (size + (chunk - 1)) & -chunk;
    for (off = 0; size > 0; off += chunk) {
        D_00221E20[0] = 0x10000006;
        D_00221E20[1] = 0;
        D_00221E20[2] = 0;
        D_00221E20[3] = 0x50000006;
        D_00221E20 += 4;
        func_00138E08(D_00221E20, (tbp + off) >> 8, width >> 6, 0, 0, 0, width, 32);
        D_00221E20 += 0x18;
        D_00221E20[0] = (chunk >> 4) | 0x30000000;
        D_00221E20[1] = (u32)(src + off);
        D_00221E20[2] = 0;
        D_00221E20[3] = (chunk >> 4) | 0x50000000;
        D_00221E20 += 4;
        size -= chunk;
    }
    return (u64)(tbp >> 8) | ((u64)(width >> 6) << 14) | ((u64)log_w << 26) | ((u64)log_h << 30)
         | ((u64)1 << 34);
}
