#include "common.h"
/* Ported from rac3-decomp's func_L39_006CD588 (src/levels/39_multiplayer_menu/L39_006CCE90.c, GPL-3.0), the same code in both games. */

s32 func_L00_0077D148(s32, s32, s32, s32);
s32 func_L00_007663C8(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L00_0077D148(r, arg1 * 2, 0xD0, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
extern s32 func_L00_0077D148(s32, s32, s32, s32);
