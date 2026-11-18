#include "common.h"
/* Ported from rac3-decomp's func_L39_006CD5F0 (src/levels/39_multiplayer_menu/L39_006CCE90.c, GPL-3.0), the same code in both games. */

s32 func_L00_00782528(s32, s32, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CD5F0;
typedef struct {
    u8 padding_0[0x4B8];
    u8 f4B8;
    u8 padding_4B9[0x7];
    u8 f4C0;
    u8 padding_4C1[0xB];
    s32 f4CC;
    L_006CD5F0 f4D0;
    L_006CD5F0 f4DC;
    s32 f4E8;
    u32 f4EC;
} Type1;
extern s32 func_L00_00782528(s32, s32, s32, s32);
extern s32 func_L00_007824D0(s32, s32, s32, s32);
extern void func_0011A518(void *, s32, s32);
void func_L00_0076C5F0(Type1 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CD5F0 *a;
    L_006CD5F0 *b;
    if (s->f4B8 == 0) {
        s->f4C0 = 0;
        s->f4CC = n;
        s->f4B8 = 1;
        buf = base;
        r = func_L00_00782528(base, n * 2, 72, 4);
        s->f4E8 = func_L00_007824D0(buf, r, 72, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f4EC = buf;
        func_0011A518((void *)buf, 0, s->f4CC * 8);
        a = &s->f4D0;
        b = &s->f4DC;
        a->f0 = 0;
        a->f8 = s->f4EC;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f4CC * 4 + s->f4EC;
        b->f4 = 0;
    }
}
