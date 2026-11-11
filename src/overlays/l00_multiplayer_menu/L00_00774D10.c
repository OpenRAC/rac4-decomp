#include "common.h"
/* Ported from rac3-decomp's func_L39_006D9090 (src/levels/39_multiplayer_menu/L39_006D8E90.c, GPL-3.0), the same code in both games. */

s32 func_0015DB80(s32, s32);
void *func_L00_00771A20(void *arg0);
void *func_L00_00774D10(u32 arg0) {
    u32 align = 4;
    u32 r = arg0;
    u32 rem = arg0 % align;
    void *p;
    if (rem != 0) {
        r = arg0 + (align - rem);
    }
    p = (void *) func_0015DB80(0x88, (s32) r);
    return func_L00_00771A20(p);
}
