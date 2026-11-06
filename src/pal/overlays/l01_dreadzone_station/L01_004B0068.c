/* cflags: -ffast-math */
#include "common.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

extern s32 D_0021DE40;
extern u8 *D_003660F8[10];

// After the first 50 frames (D_0021DE40), keeps in vars+0x6C the highest +0x2E20 seen for each
// of the 10 players of D_003660F8, and returns 0 as soon as a player's current value is below its
// highest, otherwise 1. func_L01_004B00E8 is the same with the results swapped. Built with
// -ffast-math for retail's max.s.
s32 func_L01_004B0068(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    f32 *best;
    u8 *p;
    s32 i;

    if (D_0021DE40 < 50) {
        return 1;
    }
    best = (f32 *)(vars + 0x6C);
    for (i = 0, p = D_003660F8[0]; i < 10; p = D_003660F8[++i]) {
        if (p != NULL) {
            best[i] = MAX(*(f32 *)(p + 0x2E20), best[i]);
            if (*(f32 *)(p + 0x2E20) < best[i]) {
                return 0;
            }
        }
    }
    return 1;
}
