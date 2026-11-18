#include "common.h"
/* Ported from rac3-decomp's func_L39_006CD5F0 (src/levels/39_multiplayer_menu/L39_006CCE90.c, GPL-3.0), the same code in both games. */

s32 func_L00_00782528(s32, s32, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CD5F0;
typedef struct {
    u8 padding_0[0x3D0];
    u8 f3D0;
    u8 padding_3D1[0x7];
    u8 f3D8;
    u8 padding_3D9[0xB];
    s32 f3E4;
    L_006CD5F0 f3E8;
    L_006CD5F0 f3F4;
    s32 f400;
    u32 f404;
} Type1;
extern s32 func_L00_00782528(s32, s32, s32, s32);
extern s32 func_L00_007824D0(s32, s32, s32, s32);
extern void func_0011A518(void *, s32, s32);
void func_L00_0076C0B0(Type1 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CD5F0 *a;
    L_006CD5F0 *b;
    if (s->f3D0 == 0) {
        s->f3D8 = 0;
        s->f3E4 = n;
        s->f3D0 = 1;
        buf = base;
        r = func_L00_00782528(base, n * 2, 476, 4);
        s->f400 = func_L00_007824D0(buf, r, 476, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f404 = buf;
        func_0011A518((void *)buf, 0, s->f3E4 * 8);
        a = &s->f3E8;
        b = &s->f3F4;
        a->f0 = 0;
        a->f8 = s->f404;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f3E4 * 4 + s->f404;
        b->f4 = 0;
    }
}
