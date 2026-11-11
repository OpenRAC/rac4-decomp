#include "common.h"
/* Ported from rac3-decomp's func_L39_006D6520 (src/levels/39_multiplayer_menu/L39_006D4ED8.c, GPL-3.0), the same code in both games. */

typedef struct {
    s8 f0;
    u8 pad1[3];
    s32 f4;
    s8 f8;
    u8 pad9[3];
    s32 fC;
    s32 f10;
    s8 f14;
    s8 f15;
} S_006D6520;
S_006D6520 *func_L00_00771A20(S_006D6520 *arg0) {
    arg0->f0 = 0;
    arg0->f4 = -1;
    arg0->f8 = 0;
    arg0->fC = -1;
    arg0->f10 = -1;
    arg0->f14 = 0;
    arg0->f15 = 0;
    return arg0;
}
