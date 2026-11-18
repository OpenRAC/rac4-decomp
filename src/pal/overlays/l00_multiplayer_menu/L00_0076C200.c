#include "common.h"
/* Ported from rac3-decomp's func_L39_006CD5F0 (src/levels/39_multiplayer_menu/L39_006CCE90.c, GPL-3.0), the same code in both games. */

s32 func_L00_00782528(s32, s32, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CD5F0;
typedef struct {
    u8 padding_0[0x408];
    u8 f408;
    u8 padding_409[0x7];
    u8 f410;
    u8 padding_411[0xB];
    s32 f41C;
    L_006CD5F0 f420;
    L_006CD5F0 f42C;
    s32 f438;
    u32 f43C;
} Type1;
extern s32 func_L00_00782528(s32, s32, s32, s32);
extern s32 func_L00_007824D0(s32, s32, s32, s32);
extern void func_0011A518(void *, s32, s32);
void func_L00_0076C200(Type1 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CD5F0 *a;
    L_006CD5F0 *b;
    if (s->f408 == 0) {
        s->f410 = 0;
        s->f41C = n;
        s->f408 = 1;
        buf = base;
        r = func_L00_00782528(base, n * 2, 212, 4);
        s->f438 = func_L00_007824D0(buf, r, 212, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f43C = buf;
        func_0011A518((void *)buf, 0, s->f41C * 8);
        a = &s->f420;
        b = &s->f42C;
        a->f0 = 0;
        a->f8 = s->f43C;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f41C * 4 + s->f43C;
        b->f4 = 0;
    }
}
