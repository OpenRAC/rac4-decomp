#include "common.h"

extern void func_00158C70(s32 a0, s32 a1, void *a2, s32 a3, s64 t0);

/* PAL: from rac2-decomp's func_00133340 */
void func_00159268(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s64 arg11) {
    s32 buf[8];
    s32 p02;
    s32 p13;
    p13 = ((u32)arg5 << 16) | (arg3 & 0xFFFF);
    p02 = ((u32)arg4 << 16) | (arg2 & 0xFFFF);
    buf[0] = arg0;
    buf[1] = arg1;
    buf[2] = p02;
    buf[3] = p13;
    buf[4] = arg6;
    buf[5] = arg7;
    buf[6] = arg8;
    buf[7] = arg9;
    func_00158C70(0x2C, 0x20, buf, arg10, arg11);
}
