/* Not matching yet: BYTES 0/272, exact only with inline asm (plzcw), which matched C may not use (tools/check_func.py func_004F6EF8). Not part of the build. */
#include "common.h"

extern void func_004F6D08(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                          s32, s32, s32);

/* plzcw (R5900 MMI): leading sign bits minus one, so 30 - n is floor(log2(x)) for x > 0. No C form
 * gives retail's bare plzcw: SN's __builtin_plzcw works on 128-bit values and adds por copies and a
 * sign extension. */
static inline s32 lead_sign_bits(s32 x)
{
    s32 r;
    __asm__("plzcw %0, %1" : "=r"(r) : "r"(x));
    return r;
}

void func_004F6EF8(s32 a0, s32 a1, s32 a2, s32 width, s32 height, s32 a5, s32 width2, s32 height2)
{
    s32 log_w;
    s32 log_h;

    if (width < 64) {
        width = 64;
    }
    if (height < 64) {
        height = 64;
    }
    if (width2 < 64) {
        width2 = 64;
    }
    if (height2 < 64) {
        height2 = 64;
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
    func_004F6D08(a0, a1, a2, width, height, width >> 6, log_w, log_h, a5, width2, height2, width2 >> 6, 0x98,
                  0x98, width2 * 16 + 0x98, height2 * 16 + 0x98, 0, 0, width * 16, height * 16);
}
