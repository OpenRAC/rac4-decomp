/* cflags: -mno-split-addresses */
#include "common.h"

extern u8 *D_002226A0[];
extern void func_L07_0053F810(u8 *a0, u8 *a1, s32 a2, s32 a3, u8 *t0, u8 *t1);

/* from rac3-decomp's func_L05_004512F8 */
void func_L07_0053F8C0(u8 *a0, s32 a1, s32 a2, s32 a3) {
    if (a3 != -1) {
        u8 *t = D_002226A0[0] + (a3 << 7);
        func_L07_0053F810(a0 + 16, a0 + 240, a1, a2, t + 48, t + 112);
    }
}
