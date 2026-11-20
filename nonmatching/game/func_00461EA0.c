/* Not matching yet: BYTES 0/476, exact only with inline asm (plzcw), which matched C may not use (tools/check_func.py func_00461EA0). Not part of the build. */
#include "common.h"

typedef struct TexImage {
    s32 pad0[2];
    s32 width;
    s32 height;
    s32 pad10[4];
    u8 clut[0x400];
    u8 pixels[1];
} TexImage;

extern void func_00138E08(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_00126E20(s32);
extern void func_00139130(void *, void *);
extern void func_00131A08(s32, s32);

/* plzcw (R5900 MMI): leading sign bits minus one, so 30 - n is floor(log2(x)) for x > 0. No C form
 * gives retail's bare plzcw: SN's __builtin_plzcw works on 128-bit values and adds por copies and a
 * sign extension. */
static inline s32 lead_sign_bits(s32 x)
{
    s32 r;
    __asm__("plzcw %0, %1" : "=r"(r) : "r"(x));
    return r;
}

s32 func_00461EA0(s32 tbp, s32 cbp, s32 *bundle, s32 *countp, u64 *out)
{
    u8 gs[0x60];
    s32 *offp = bundle;
    s32 i;

    *countp = *offp++;
    for (i = 0; i < *countp;) {
        TexImage *img = (TexImage *)((u8 *)bundle + *offp);
        u8 *clut = img->clut;
        s32 cbp8 = cbp >> 8;
        s32 tbp8;
        s32 tbw;
        s32 lw;

        func_00138E08(gs, cbp8, 1, 0, 0, 0, 16, 16);
        func_00126E20(0);
        tbp8 = tbp >> 8;
        func_00139130(gs, clut);
        cbp += 0x400;
        offp++;
        func_00131A08(0, 0);
        tbw = img->width >> 6;
        lw = 30 - lead_sign_bits(img->width);
        if (tbw <= 0) {
            tbw = 1;
        }
        func_00138E08(gs, tbp8, tbw, 0x1B, 0, 0, img->width, img->height);
        func_00126E20(0);
        func_00139130(gs, img->pixels);
        func_00131A08(0, 0);
        out[i] = (u64)tbp8 | ((u64)tbw << 14) | ((u64)0x1B << 20) | ((u64)lw << 26) | ((u64)lw << 30)
               | ((u64)1 << 34) | ((u64)cbp8 << 37) | ((u64)4 << 61);
        tbp += img->width * img->height * 4;
        i++;
    }
    return tbp;
}
