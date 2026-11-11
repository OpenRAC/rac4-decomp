#include "common.h"

extern void *func_0053C920(s32, s32, s32, s32);
extern void func_0053CAA8(void *, void *, s32);

s32 D_00220DDC = 0;

/* from rac3-decomp's func_L39_0066DC28 */
void func_005409F0(s32 *a, u8 b, u8 c) {
    u8 tmp[16];
    s32 w[4];
    s32 m = (s32)func_0053C920(D_00220DDC, 2, 0, 0);
    *(s32 *)(m + 80) = a[18];
    w[0] = a[0];
    func_0053CAA8((void *)m, w, 4);
    tmp[0] = b;
    func_0053CAA8((void *)m, tmp, 1);
    tmp[0] = c;
    func_0053CAA8((void *)m, tmp, 1);
}
