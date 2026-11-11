#include "common.h"
/* Ported from rac3-decomp's func_L39_006DD468 (src/levels/39_multiplayer_menu/L39_006DC228.c, GPL-3.0), the same code in both games. */

s32 func_L00_0077D148(s32, s32, s32, s32);
s32 func_L00_0077B9C0(void *arg0, s32 arg1) {
    u32 end = (u32)arg0 + func_L00_0077D148((s32)arg0, arg1 * 2, 0x40C, 4);
    u32 aligned;
    {
        u32 x = end;
        u32 a = 4;
        u32 r = x % a;
        if (r != 0) {
            x += a - r;
        }
        aligned = x;
    }
    end = aligned + arg1 * 8;
    return end - (u32)arg0;
}
