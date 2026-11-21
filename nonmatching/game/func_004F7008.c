/* Not matching yet: BYTES 0/1048, exact only with inline asm (plzcw), which matched C may not use (tools/check_func.py func_004F7008). Not part of the build. */
#include "common.h"

extern void func_004F6648(u64 **, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* plzcw (R5900 MMI): leading sign bits minus one, so 30 - n is floor(log2(x)) for x > 0. No C form
 * gives retail's bare plzcw: SN's __builtin_plzcw works on 128-bit values and adds por copies and a
 * sign extension. */
static inline s32 lead_sign_bits(s32 x)
{
    s32 r;
    __asm__("plzcw %0, %1" : "=r"(r) : "r"(x));
    return r;
}

void func_004F7008(u64 **pp, s32 tbp, s32 width, s32 height, s32 fbp)
{
    s32 sw = width << 4;
    s32 sh = height << 4;
    s32 ex = sw + 0xA0;
    s32 ey = sh + 0xA0;
    s32 ex2 = (width + 1) << 4;
    s32 ey2 = (height + 1) << 4;
    s32 log_w;
    s32 log_h;

    if (width < 64) {
        width = 64;
    }
    if (height < 64) {
        height = 64;
    }

    if (width & (width - 1)) {
        log_w = 31 - lead_sign_bits(width);
    } else {
        log_w = 30 - lead_sign_bits(width);
    }
    if (height & (height - 1)) {
        log_h = 31 - lead_sign_bits(height);
    } else {
        log_h = 30 - lead_sign_bits(height);
    }
    *(*pp)++ = 0x1000000000000005;
    *(*pp)++ = 0xE;
    *(*pp)++ = ((u64)(width - 1) << 16) | ((u64)(height - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = (u64)(tbp >> 8) | ((u64)(width >> 6) << 14) | ((u64)log_w << 26) | ((u64)log_h << 30) | ((u64)1 << 34);
    *(*pp)++ = 0x7;
    *(*pp)++ = (u64)(fbp >> 13) | ((u64)(width >> 6) << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x60;
    *(*pp)++ = 0x15;
    *(*pp)++ = 0x5;
    *(*pp)++ = 0x9;
    *(*pp)++ = 0x2400000000000001;
    *(*pp)++ = 0x1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x316;
    func_004F6648(pp, 0xA0, 0xA0, 0, 0, ex, ey, sw, sh, 0);
    *(*pp)++ = 0x1000000000000001;
    *(*pp)++ = 0xE;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0x1000000000000002;
    *(*pp)++ = 0xE;
    *(*pp)++ = (u64)(fbp >> 8) | ((u64)(width >> 6) << 14) | ((u64)log_w << 26) | ((u64)log_h << 30) | ((u64)1 << 34);
    *(*pp)++ = 0x7;
    *(*pp)++ = (u64)(tbp >> 13) | ((u64)(width >> 6) << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x2400000000000001;
    *(*pp)++ = 0x1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x316;
    func_004F6648(pp, 0xA0, 0xA0, 0x10, 0x10, ex, ey, ex2, ey2, 0);
    *(*pp)++ = 0x1000000000008001;
    *(*pp)++ = 0xE;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
