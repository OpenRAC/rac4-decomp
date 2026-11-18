#include "common.h"
/* Ported from rac3-decomp's func_L39_006CD5F0 (src/levels/39_multiplayer_menu/L39_006CCE90.c, GPL-3.0), the same code in both games. */

s32 func_L00_00782528(s32, s32, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CD5F0;
typedef struct {
    u8 padding_0[0x440];
    u8 f440;
    u8 padding_441[0x7];
    u8 f448;
    u8 padding_449[0xB];
    s32 f454;
    L_006CD5F0 f458;
    L_006CD5F0 f464;
    s32 f470;
    u32 f474;
} Type1;
extern s32 func_L00_00782528(s32, s32, s32, s32);
extern s32 func_L00_007824D0(s32, s32, s32, s32);
extern void func_0011A518(void *, s32, s32);
void func_L00_0076C350(Type1 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CD5F0 *a;
    L_006CD5F0 *b;
    if (s->f440 == 0) {
        s->f448 = 0;
        s->f454 = n;
        s->f440 = 1;
        buf = base;
        r = func_L00_00782528(base, n * 2, 276, 4);
        s->f470 = func_L00_007824D0(buf, r, 276, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f474 = buf;
        func_0011A518((void *)buf, 0, s->f454 * 8);
        a = &s->f458;
        b = &s->f464;
        a->f0 = 0;
        a->f8 = s->f474;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f454 * 4 + s->f474;
        b->f4 = 0;
    }
}
