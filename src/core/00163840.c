#include "common.h"

extern void func_001634F0(f32 fparg0);
extern s32 func_00163928(void);
extern s32 D_21D940[];

/* Stores the seven arguments in the block at D_21D940, sets bit 0 of its word 2, then calls func_001634F0(0.0); returns 1. */
s32 func_00163840(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 *g;

    func_00163928();
    g = D_21D940;
    g[4] = arg6;
    g[5] = arg0;
    g[8] = arg1;
    g[9] = arg2;
    g[10] = arg3;
    g[11] = arg4;
    g[3] = arg5;
    g[2] |= 1;
    func_001634F0(0.0f);
    return 1;
}
