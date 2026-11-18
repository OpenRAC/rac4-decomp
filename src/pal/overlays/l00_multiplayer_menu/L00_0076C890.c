#include "common.h"
/* Ported from rac3-decomp's func_L39_006CD5F0 (src/levels/39_multiplayer_menu/L39_006CCE90.c, GPL-3.0), the same code in both games. */

s32 func_L00_00782528(s32, s32, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CD5F0;
typedef struct {
    u8 padding_0[0x531];
    u8 f531;
    u8 padding_532[0x6];
    u8 f538;
    u8 padding_539[0xB];
    s32 f544;
    L_006CD5F0 f548;
    L_006CD5F0 f554;
    s32 f560;
    u32 f564;
} Type1;
extern s32 func_L00_00782528(s32, s32, s32, s32);
extern s32 func_L00_007824D0(s32, s32, s32, s32);
extern void func_0011A518(void *, s32, s32);
void func_L00_0076C890(Type1 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CD5F0 *a;
    L_006CD5F0 *b;
    if (s->f531 == 0) {
        s->f538 = 0;
        s->f544 = n;
        s->f531 = 1;
        buf = base;
        r = func_L00_00782528(base, n * 2, 40, 4);
        s->f560 = func_L00_007824D0(buf, r, 40, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f564 = buf;
        func_0011A518((void *)buf, 0, s->f544 * 8);
        a = &s->f548;
        b = &s->f554;
        a->f0 = 0;
        a->f8 = s->f564;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f544 * 4 + s->f564;
        b->f4 = 0;
    }
}
