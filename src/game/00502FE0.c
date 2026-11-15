/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 func_00502440(s32 *arg0);
extern s32 func_00502448(s32 *arg0);
extern f32 func_00502450(f32 *arg0);
extern s32 func_00502478(u8 *arg0, u32 arg1);
extern u8 *func_005033D0(u8 *p, s32 base, s32 id, s32 flags);
extern s32 func_00503920(s32 id, s32 arg1);
extern s32 func_00504D68(s32 handle, float *a, float *b);
extern s32 func_00504E68(s32 handle, float *a, float *b);
extern s32 func_00504F68(u32 id, s32 enabled);
extern s32 func_00505DD0(u32 id, s32 amount);
extern void func_00506930(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

/* Reads the parameter block at arg0 (after one extra buffer when arg3 bit 0 is set), sets up the object and returns the next pointer. */
s32 func_00502FE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 flag;
    s32 p;
    s32 sp0;
    s32 s0;
    s32 s2;
    s32 s3;
    s32 s5;
    s32 s6;
    s32 temp;
    s32 h;
    s32 i;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;

    flag = arg3 & 1;
    sp0 = arg2;
    p = arg0;
    if (flag != 0) {
        p = func_00502478((u8 *)func_00502478((u8 *)p, 0x1000), 0x1000);
    }
    temp = func_00502448((s32 *)p);
    p += 4;
    s6 = temp;
    s2 = func_00502448((s32 *)p) + arg1;
    p += 4;
    f23 = func_00502450((f32 *)p);
    p += 4;
    f22 = func_00502450((f32 *)p);
    p += 4;
    f21 = func_00502450((f32 *)p);
    p += 4;
    f20 = func_00502450((f32 *)p);
    p += 4;
    s0 = func_00502440((s32 *)p);
    p += 4;
    h = func_00502448((s32 *)p);
    s5 = h != 0;
    p += 4;
    i = func_00502448((s32 *)p);
    p += 4;
    func_00506930(s2, i, 0, f23, f22, f21, f20);
    func_00503920(s2, s0);
    for (s3 = 0; s3 < 8; s3++) {
        func_00504D68(s2, (float *)(1 << s3), (float *)(s6 & (1 << s3)));
    }
    func_00504F68(s2, s5);
    func_00504E68(s2, (float *)3, (float *)3);
    p = (s32)func_005033D0((u8 *)p, arg1, s2, arg3);
    if (flag != 0) {
        p = func_00502478((u8 *)p, 0x1000);
    }
    func_00505DD0(sp0, s2);
    return p;
}
