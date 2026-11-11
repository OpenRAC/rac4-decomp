#include "common.h"
/* Ported from rac3-decomp's func_L39_006D65D0 (src/levels/39_multiplayer_menu/L39_006D4ED8.c, GPL-3.0), the same code in both games. */

s32 func_L00_0077D148(s32, s32, s32, s32);
s32 func_L00_0077D0F0(s32, s32, s32, s32);
void func_0011A518(s32 *, s32, s32);
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} S_006D65D0_Node;
void func_L00_00771AF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *s = (u8 *)arg0;
    u32 r;
    u32 m;
    u32 rem;
    u32 a;
    s32 n;
    S_006D65D0_Node *p;
    S_006D65D0_Node *q;
    if (*s == 0) {
        r = arg1;
        s[8] = 0;
        *(s32 *)(s + 0x64) = arg3;
        *s = 1;
        n = func_L00_0077D148(r, arg3 * 2, 0x1D8, 4);
        *(s32 *)(s + 0x80) = func_L00_0077D0F0(r, n, 0x1D8, 4);
        r += n;
        m = 4;
        rem = r % m;
        a = r;
        if (rem != 0) {
            a = r + (m - rem);
        }
        r = a;
        *(s32 *)(s + 0x84) = r;
        func_0011A518((s32 *)r, 0, *(s32 *)(s + 0x64) * 8);
        p = (S_006D65D0_Node *)(s + 0x68);
        p->f0 = 0;
        p->f8 = *(s32 *)(s + 0x84);
        p->f4 = 0;
        q = (S_006D65D0_Node *)(s + 0x74);
        q->f0 = 0;
        q->f8 = *(s32 *)(s + 0x64) * 4 + *(s32 *)(s + 0x84);
        q->f4 = 0;
    }
}
void func_L00_00771AF0(s32, s32, s32, s32);
