#include "common.h"
/* Ported from rac3-decomp's func_L39_006DA1C0 (src/levels/39_multiplayer_menu/L39_006D8E90.c, GPL-3.0), the same code in both games. */

s32 func_L00_0077D148(void *, s32, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} Q_006DA1C0;
typedef struct {
    u8 pad0[0x15C];
    u8 f15C;
    u8 f15D;
    u8 pad15E[0x16];
    s32 f174;
    Q_006DA1C0 f178;
    Q_006DA1C0 f184;
    s32 f190;
    s32 f194;
} S_006DA1C0;
s32 func_L00_0077D0F0(s32, s32, s32, s32);
void func_0011A518(s32, s32, s32);
void func_L00_007772E8(S_006DA1C0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 r;
    s32 n;
    Q_006DA1C0 *q;
    Q_006DA1C0 *q2;
    if (arg0->f15C == 0) {
        arg0->f15D = 0;
        arg0->f174 = arg3;
        arg0->f15C = 1;
        r = arg1;
        n = func_L00_0077D148((void *)arg1, arg3 * 2, 0xD0, 4);
        arg0->f190 = func_L00_0077D0F0(r, n, 0xD0, 4);
        r += n;
        {
            u32 align = 4;
            u32 t = r;
            u32 rem = r % align;
            if (rem != 0) {
                t = r + (align - rem);
            }
            r = t;
        }
        arg0->f194 = r;
        func_0011A518(r, 0, arg0->f174 * 8);
        q = &arg0->f178;
        q->f0 = 0;
        q->f8 = arg0->f194;
        q->f4 = 0;
        q2 = &arg0->f184;
        q2->f0 = 0;
        q2->f8 = arg0->f174 * 4 + arg0->f194;
        q2->f4 = 0;
    }
}
