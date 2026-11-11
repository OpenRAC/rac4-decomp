#include "common.h"
/* Ported from rac3-decomp's func_L39_004BECC0 (src/levels/39_multiplayer_menu/L39_004BECC0.c, GPL-3.0), the same code in both games. */

extern s32 (*D_00498E18[])(void);
s32 func_L00_004FAAC0(void) {
    s32 (*fn)(void) = D_00498E18[0];
    s32 ret;
    do {
        ret = 1;
        if (fn == 0) {
            break;
        }
        ret = fn();
    } while (0);
    return ret;
}
