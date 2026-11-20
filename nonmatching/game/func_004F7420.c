/* Not matching yet: BYTES 0/924, exact only with inline asm (plzcw), which matched C may not use (tools/check_func.py func_004F7420). Not part of the build. */
/* cflags: -mno-split-addresses */
#include "pal/command_buffer.h"

extern char D_00003E90[];

extern void func_004F6750(PalCommandCursor *, s32 *, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* plzcw (R5900 MMI): leading sign bits minus one, so 30 - n is floor(log2(x)) for x > 0. No C form
 * gives retail's bare plzcw: SN's __builtin_plzcw works on 128-bit values and adds por copies and a
 * sign extension. */
static inline s32 lead_sign_bits(s32 x)
{
    s32 r;
    __asm__("plzcw %0, %1" : "=r"(r) : "r"(x));
    return r;
}

void func_004F7420(PalCommandCursor *p, s32 *n, s32 tbp, s32 width, s32 height, s32 fbp)
{
    u64 **q = &p->pairs;
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
    *(*q)++ = (u64)(*n | 0x64078000) << 32;
    *(*q)++ = 0x118B400000008006ULL;
    *(*q)++ = ((u64)(width - 1) << 16) | ((u64)(height - 1) << 48);
    *(*q)++ = (u64)(tbp >> 8) | ((u64)(width >> 6) << 14) | ((u64)log_w << 26) | ((u64)log_h << 30) | ((u64)1 << 34);
    *(*q)++ = (u64)(fbp >> 13) | ((u64)(width >> 6) << 16);
    *(*q)++ = 0x60;
    *(*q)++ = 5;
    *(*q)++ = 0x80808080;
    *(*q)++ = (u32)(*n | 0x72078000) | 0x4D07410E00000000ULL;
    *(*q)++ = ((u64)(u32)(((s32)D_00003E90 >> 3) | 0x14000000) << 32) | 0x10915;
    *n += 7;
    func_004F6750(p, n, 0xA0, 0xA0, 0, 0, (width << 4) + 0xA0, (height << 4) + 0xA0, width << 4, height << 4, 0);
    *(*q)++ = (u64)(*n | 0x64038000) << 32;
    *(*q)++ = 0x1000000000008002ULL;
    *(*q)++ = (u64)(fbp >> 8) | ((u64)(width >> 6) << 14) | ((u64)log_w << 26) | ((u64)log_h << 30) | ((u64)1 << 34);
    *(*q)++ = (u64)(tbp >> 13) | ((u64)(width >> 6) << 16);
    *(*q)++ = (u32)(*n | 0x72038000) | 0x4D070E00000000ULL;
    *(*q)++ = (u32)(((s32)D_00003E90 >> 3) | 0x14000000);
    *n += 3;
    func_004F6750(p, n, 0xA0, 0xA0, 0x10, 0x10, (width << 4) + 0xA0, (height << 4) + 0xA0, (width + 1) << 4,
                  (height + 1) << 4, 0);
}
