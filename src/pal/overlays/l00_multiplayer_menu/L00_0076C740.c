#include "common.h"
/* Ported from rac3-decomp's func_L39_006CD5F0 (src/levels/39_multiplayer_menu/L39_006CCE90.c, GPL-3.0), the same code in both games. */

s32 func_L00_00782528(s32, s32, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CD5F0;
typedef struct {
    u8 padding_0[0x4F8];
    u8 f4F8;
    u8 padding_4F9[0x7];
    u8 f500;
    u8 padding_501[0xB];
    s32 f50C;
    L_006CD5F0 f510;
    L_006CD5F0 f51C;
    s32 f528;
    u32 f52C;
} Type1;
extern s32 func_L00_00782528(s32, s32, s32, s32);
extern s32 func_L00_007824D0(s32, s32, s32, s32);
extern void func_0011A518(void *, s32, s32);
void func_L00_0076C740(Type1 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CD5F0 *a;
    L_006CD5F0 *b;
    if (s->f4F8 == 0) {
        s->f500 = 0;
        s->f50C = n;
        s->f4F8 = 1;
        buf = base;
        r = func_L00_00782528(base, n * 2, 452, 4);
        s->f528 = func_L00_007824D0(buf, r, 452, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f52C = buf;
        func_0011A518((void *)buf, 0, s->f50C * 8);
        a = &s->f510;
        b = &s->f51C;
        a->f0 = 0;
        a->f8 = s->f52C;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f50C * 4 + s->f52C;
        b->f4 = 0;
    }
}
