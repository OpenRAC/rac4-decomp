#include "common.h"

extern void func_0053DE58(void *, void *, s32);
s32 D_0022087C = 0;
extern u32 *func_0053DCD0(s32, s32, s32, s32);

/* PAL: from rac3-decomp's func_L39_0066DA90 */
void func_00541C58(s32 *a0, s32 a1, u8 a2, u8 a3) {
    u8 b[2];
    s32 w;
    u32 *s;
    s = func_0053DCD0(D_0022087C, 1, 0, 0);
    s[20] = a1;
    w = *a0;
    func_0053DE58(s, &w, 4);
    b[0] = a2;
    func_0053DE58(s, b, 1);
    b[0] = a3;
    func_0053DE58(s, b, 1);
    a0[12] = s[1] + (s[0] >> 14);
}
