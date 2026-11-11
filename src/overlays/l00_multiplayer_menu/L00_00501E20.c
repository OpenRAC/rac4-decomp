/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C6020 (src/levels/39_multiplayer_menu/L39_004C5F70.c, GPL-3.0), the same code in both games. */

typedef struct Type1 {
    u8 pad0[0x3C];
    s32 *f3C;
    s32 f40;
    s32 f44;
} Type1;
extern s32 func_L00_005017D8(Type1 *, s32, s32);
s32 func_L00_00501E20(Type1 *a0)
{
    s32 r = func_L00_005017D8(a0, a0->f3C[1] + a0->f44, a0->f40);
    if (r == a0->f40) {
        return 1;
    }
    if (r < 0) {
        return -1;
    }
    a0->f40 -= r;
    a0->f44 += r;
    return 0;
}
