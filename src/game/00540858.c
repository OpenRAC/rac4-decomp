#include "common.h"

extern void func_0053CAA8(void *, void *, s32);
s32 D_00220DDC = 0;
extern u32 *func_0053C920(s32, s32, s32, s32);

/* from rac3-decomp's func_L39_0066DA90 */
void func_00540858(s32 *a0, s32 a1, u8 a2, u8 a3) {
    u8 b[2];
    s32 w;
    u32 *s;
    s = func_0053C920(D_00220DDC, 1, 0, 0);
    s[20] = a1;
    w = *a0;
    func_0053CAA8(s, &w, 4);
    b[0] = a2;
    func_0053CAA8(s, b, 1);
    b[0] = a3;
    func_0053CAA8(s, b, 1);
    a0[12] = s[1] + (s[0] >> 14);
}
