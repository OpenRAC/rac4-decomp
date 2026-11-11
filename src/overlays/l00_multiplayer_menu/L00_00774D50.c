#include "common.h"
/* Ported from rac3-decomp's func_L39_006D90D0 (src/levels/39_multiplayer_menu/L39_006D8E90.c, GPL-3.0), the same code in both games. */

u32 func_L00_00774D50(u32 arg0);
u32 func_L00_00774D50(u32 arg0) {
    u32 align = 4;
    u32 aligned = arg0;
    u32 rem = arg0 % align;
    if (rem != 0) {
        aligned = arg0 + (align - rem);
    }
    return aligned - arg0 + 0x88;
}
