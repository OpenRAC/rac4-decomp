#include "common.h"
/* Ported from rac3-decomp's func_L39_006CD5F0 (src/levels/39_multiplayer_menu/L39_006CCE90.c, GPL-3.0), the same code in both games. */

s32 func_L00_00782528(s32, s32, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CD5F0;
typedef struct {
    u8 padding_0[0x198];
    u8 f198;
    u8 f199;
    u8 padding_19A[0x16];
    s32 f1B0;
    L_006CD5F0 f1B4;
    L_006CD5F0 f1C0;
    s32 f1CC;
    u32 f1D0;
} Type1;
extern s32 func_L00_00782528(s32, s32, s32, s32);
extern s32 func_L00_007824D0(s32, s32, s32, s32);
extern void func_0011A518(void *, s32, s32);
void func_L00_0077C810(Type1 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CD5F0 *a;
    L_006CD5F0 *b;
    if (s->f198 == 0) {
        s->f199 = 0;
        s->f1B0 = n;
        s->f198 = 1;
        buf = base;
        r = func_L00_00782528(base, n * 2, 132, 4);
        s->f1CC = func_L00_007824D0(buf, r, 132, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f1D0 = buf;
        func_0011A518((void *)buf, 0, s->f1B0 * 8);
        a = &s->f1B4;
        b = &s->f1C0;
        a->f0 = 0;
        a->f8 = s->f1D0;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f1B0 * 4 + s->f1D0;
        b->f4 = 0;
    }
}
