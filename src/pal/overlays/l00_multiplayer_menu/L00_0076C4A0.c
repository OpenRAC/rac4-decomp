#include "common.h"
/* Ported from rac3-decomp's func_L39_006CD5F0 (src/levels/39_multiplayer_menu/L39_006CCE90.c, GPL-3.0), the same code in both games. */

s32 func_L00_00782528(s32, s32, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CD5F0;
typedef struct {
    u8 padding_0[0x478];
    u8 f478;
    u8 padding_479[0x7];
    u8 f480;
    u8 padding_481[0xB];
    s32 f48C;
    L_006CD5F0 f490;
    L_006CD5F0 f49C;
    s32 f4A8;
    u32 f4AC;
} Type1;
extern s32 func_L00_00782528(s32, s32, s32, s32);
extern s32 func_L00_007824D0(s32, s32, s32, s32);
extern void func_0011A518(void *, s32, s32);
void func_L00_0076C4A0(Type1 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CD5F0 *a;
    L_006CD5F0 *b;
    if (s->f478 == 0) {
        s->f480 = 0;
        s->f48C = n;
        s->f478 = 1;
        buf = base;
        r = func_L00_00782528(base, n * 2, 280, 4);
        s->f4A8 = func_L00_007824D0(buf, r, 280, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f4AC = buf;
        func_0011A518((void *)buf, 0, s->f48C * 8);
        a = &s->f490;
        b = &s->f49C;
        a->f0 = 0;
        a->f8 = s->f4AC;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f48C * 4 + s->f4AC;
        b->f4 = 0;
    }
}
