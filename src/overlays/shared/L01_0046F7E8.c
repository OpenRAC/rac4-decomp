#include "common.h"

extern void func_00587A98(u8 *, s32, f32 *);
extern s32 func_0053EC88(f32 *, s32, u8 *, f32);
extern s32 D_0024235C[];

/* from rac3-decomp's func_L01_0032F0D8 */
void func_L01_0046F7E8(u8 *a0) {
    f32 v[4];
    func_00587A98(a0, 0, v);
    if (func_0053EC88(v, 2, a0, 0.25f) && D_0024235C[0] > 0) {
        a0[32] = 8;
    }
}
