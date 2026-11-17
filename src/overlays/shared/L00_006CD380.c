/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 D_0021E708[];
extern s32 D_0021E70C;
extern s32 func_L00_00700708();

// Chooses a state value from the player's flags.
s32 func_L00_006CD380(u8 *p) {
    s32 r = *(s16 *)(p + 0x2F8);
    s32 v;
    if (D_0021E708[0] != 0) {
        if (D_0021E70C == 0) r = 2;
    }
    if (D_0021E70C != 0) {
        r = 1;
    } else {
        v = *(s32 *)(p + 0x25CC);
        if (v == 0x3B || (v == 0x70 && p[0x438] == 0) || v == 0x6F
            || *(s16 *)(p + 0x3D6) != 0
            || (p[0x437] != 0 && func_L00_00700708(*(s32 *)(p + 0x26E4), 0x12) != 0
                && *(s32 *)(p + 0x25CC) == 0 && *(s16 *)(p + 0x2FE) < 4)) {
            r = 1;
        }
    }
    if (r == 1) {
        if (p[0x438] != 0) {
            if (p[0x437] == 0) r = 0;
        }
    }
    return r;
}
