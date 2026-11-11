/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004EF240 (src/levels/39_multiplayer_menu/L39_004ECE38.c, GPL-3.0), the same code in both games. */

extern s32 func_L00_0052AE78(s32, u8 *, s32, s32, s32, u8 *, s32);
s32 func_L00_0052B040(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, u8 *a6, u8 *a7, s32 a8) {
    s32 len = a5 / 2;
    u8 *b = a4 + len;
    s32 i;
    len += a5 & 1;
    if (!func_L00_0052AE78(a0, a4, len, a2, a3, a6, a8)) {
        return 0;
    }
    if (!func_L00_0052AE78(a1, b, len, a2, a3, a7, a8)) {
        return 0;
    }
    for (i = 0; i < a8; i++) {
        a6[i] ^= a7[i];
    }
    return 1;
}
