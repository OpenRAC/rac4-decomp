/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004FC158 (src/levels/39_multiplayer_menu/L39_004FB668.c, GPL-3.0), the same code in both games. */

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;
extern s32 func_L00_00546E70(unsigned long);
s32 func_L00_00537F68(BitSet_004FCA98 *a0) {
    s32 n = a0->f4;
    s32 r = 0;
    if (n != 0) {
        s32 off = (n - 1) << 6;
        r = off + func_L00_00546E70(a0->f0[n - 1]);
    }
    return r;
}
