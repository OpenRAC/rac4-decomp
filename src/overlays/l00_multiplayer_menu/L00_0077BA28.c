#include "common.h"
/* Ported from rac3-decomp's func_L39_006DD4D0 (src/levels/39_multiplayer_menu/L39_006DC228.c, GPL-3.0), the same code in both games. */

void func_0011A518(void *, s32, s32);
s32 func_L00_0077D148(s32, s32, s32, s32);
typedef struct {
    u8 *f0;
    s32 f4;
    s32 f8;
} S_006DD4D0_Q;
typedef struct {
    char _p0[0x2F88];
    u8 b2F88;
    u8 b2F89;
    char _p2F8A[0x2F98 - 0x2F8A];
    s32 n;
    S_006DD4D0_Q q0;
    S_006DD4D0_Q q1;
    s32 f2FB4;
    s32 buf;
} S_006DD4D0;
void func_L00_0077D0F0(s32, s32, s32, s32);
void func_L00_0077BA28(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    S_006DD4D0 *s = (S_006DD4D0 *)arg0;
    u32 p;
    s32 size;
    S_006DD4D0_Q *q0;
    S_006DD4D0_Q *q1;
    if (s->b2F88 == 0) {
        p = arg1;
        s->b2F89 = 0;
        s->n = arg3;
        s->b2F88 = 1;
        size = func_L00_0077D148(p, arg3 * 2, 0x40C, 4);
        s->f2FB4 = ((s32 (*)(s32, s32, s32, s32))func_L00_0077D0F0)(p, size, 0x40C, 4);
        p += size;
        {
            u32 x = p;
            u32 m = 4;
            u32 r = x % m;
            if (r != 0) {
                x += m - r;
            }
            p = x;
        }
        s->buf = p;
        func_0011A518((void *)p, 0, s->n * 8);
        q0 = &s->q0;
        q1 = &s->q1;
        q0->f0 = 0;
        q0->f8 = s->buf;
        q0->f4 = 0;
        q1->f0 = 0;
        q1->f8 = s->n * 4 + s->buf;
        q1->f4 = 0;
    }
}
