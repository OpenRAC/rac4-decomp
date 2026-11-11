#include "common.h"
/* Ported from rac3-decomp's func_L01_004C6030 (src/levels/shared/L01_004C5F70.c, GPL-3.0), the same code in both games. */

extern u32 *D_00222EE0;
extern void func_00138E08(void *, s16, s16, s16, s32, s32, s16, s16);
void func_L00_006796D0(s32 a0, s32 a1, s32 size) {
    s32 n;
    s32 dst = 0;
    s32 src = 0;
    n = (size + 0x3FFF) & ~0x3FFF;
    while (n > 0) {
        D_00222EE0[0] = 0x10000006;
        D_00222EE0[1] = 0;
        D_00222EE0[2] = 0;
        D_00222EE0[3] = 0x50000006;
        D_00222EE0 += 4;
        func_00138E08(D_00222EE0, (a1 + dst) >> 8, 1, 1, 0, 0, 64, 64);
        dst += 0x4000;
        n -= 0x4000;
        D_00222EE0 = (u32 *)((u8 *)D_00222EE0 + 0x60);
        D_00222EE0[0] = 0x30000300;
        D_00222EE0[1] = a0 + src;
        D_00222EE0[2] = 0;
        D_00222EE0[3] = 0x50000300;
        D_00222EE0 += 4;
        src += 0x3000;
    }
}
