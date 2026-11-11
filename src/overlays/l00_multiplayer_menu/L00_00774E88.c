#include "common.h"
/* Ported from rac3-decomp's func_L39_006D9208 (src/levels/39_multiplayer_menu/L39_006D8E90.c, GPL-3.0), the same code in both games. */

u32 func_L00_00774E88(u32 a0) {
    u32 align = 4;
    u32 r = a0;
    u32 rem = a0 % align;
    if (rem != 0) {
        r = a0 + (align - rem);
    }
    return r - a0 + 0x1D4;
}
