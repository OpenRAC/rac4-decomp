#include "common.h"
/* Ported from rac3-decomp's func_L01_003F1188 (src/levels/shared/L01_003EB9C8.c, GPL-3.0), the same code in both games. */

extern u8 D_00488544[];
extern u8 D_00222080[];
extern void func_00453630(void *, s32);
void func_L00_00595640(void) {
    s32 size = D_00488544 - D_00222080;
    if ((size & 0xF) == 0 && ((u32)D_00222080 & 0xF) == 0) {
        func_00453630(D_00222080, size);
    } else {
        s32 i;
        for (i = 0; i < D_00488544 - D_00222080; i++) {
            D_00222080[i] = 0;
        }
    }
}
