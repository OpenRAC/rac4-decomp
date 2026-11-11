#include "common.h"
/* Ported from rac3-decomp's func_L39_004C4198 (src/levels/39_multiplayer_menu/L39_004C4198.c, GPL-3.0), the same code in both games. */

typedef struct {
    char _p0[0x14];
    s32 f14;
} T_004C4198;
typedef struct {
    char _p0[0x64];
    s32 f64;
    char _p68[0xDC - 0x68];
    T_004C4198 *fDC;
} Type1;
s32 func_L00_004FFF98(Type1 *arg0) {
    T_004C4198 *p;
    s32 w;
    if (arg0 != 0) {
        if (arg0->f64 != 0) {
            return arg0->f64;
        }
        p = arg0->fDC;
        if (p != 0) {
            w = p->f14;
            if (w != 0) {
                return w;
            }
        }
    }
    return 0;
}
