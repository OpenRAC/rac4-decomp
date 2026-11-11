#include "common.h"
/* Ported from rac3-decomp's func_L39_006D6E78 (src/levels/39_multiplayer_menu/L39_006D4ED8.c, GPL-3.0), the same code in both games. */

s32 func_L00_0077D148(s32, s32, s32, s32);
s32 func_L00_0077D0F0(s32, s32, s32, s32);
void func_0011A518(s32 *, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} Type1;
typedef struct {
    s8 f0;
    u8 pad1[3];
    s32 f4;
    s32 f8;
    s8 fC;
    s8 fD;
    u8 padE[2];
    s32 f10;
    Type1 f14;
    s32 f20;
    s32 f24;
} Type2;
s32 func_L00_00772AA0(s32 arg0, s32 arg1, s32 arg2) {
    Type2 *p = (Type2 *)arg0;
    u32 r;
    u32 m;
    u32 rem;
    u32 a;
    u32 b;
    s32 n;
    Type1 *l;
    p->f0 = 0;
    p->f4 = -1;
    p->f8 = -1;
    p->fC = 0;
    p->fD = 0;
    p->f10 = arg2;
    b = arg0 + 0x28;
    m = 4;
    rem = b % m;
    if (rem != 0) {
        b += m - rem;
    }
    r = b;
    n = func_L00_0077D148(r, arg2, 100, 4);
    p->f20 = func_L00_0077D0F0(r, n, 100, 4);
    r += n;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    p->f24 = r;
    func_0011A518((s32 *)r, 0, p->f10 * 4);
    l = &p->f14;
    l->f0 = 0;
    l->f8 = p->f24;
    l->f4 = 0;
    return arg0;
}
s32 func_L00_00772AA0(s32, s32, s32);
