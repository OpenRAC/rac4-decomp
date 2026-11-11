#include "common.h"
/* Ported from rac3-decomp's func_L39_006CD5F0 (src/levels/39_multiplayer_menu/L39_006CCE90.c, GPL-3.0), the same code in both games. */

s32 func_L00_0077D148(s32, s32, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CD5F0;
typedef struct {
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[0x1B];
    s32 f24;
    L_006CD5F0 f28;
    L_006CD5F0 f34;
    s32 f40;
    u32 f44;
} Type1;
extern s32 func_L00_0077D148(s32, s32, s32, s32);
extern s32 func_L00_0077D0F0(s32, s32, s32, s32);
extern void func_0011A518(void *, s32, s32);
void func_L00_00766430(Type1 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CD5F0 *a;
    L_006CD5F0 *b;
    if (s->f0 == 0) {
        s->f8 = 0;
        s->f24 = n;
        s->f0 = 1;
        buf = base;
        r = func_L00_0077D148(base, n * 2, 0xD0, 4);
        s->f40 = func_L00_0077D0F0(buf, r, 0xD0, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f44 = buf;
        func_0011A518((void *)buf, 0, s->f24 * 8);
        a = &s->f28;
        b = &s->f34;
        a->f0 = 0;
        a->f8 = s->f44;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f24 * 4 + s->f44;
        b->f4 = 0;
    }
}
