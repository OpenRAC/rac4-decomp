#include "common.h"
extern u32 *D_00221E20;
extern void func_00138E08(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_00126E20(s32);
extern int func_00139130(u64 *p1, u64 *p2);
void func_0045F200(s32 a0, s32 a1, s32 a2, s32 w, s32 h, s32 flag) {
    u64 buf[12];
    u32 *p;
    s32 t4 = (1 << w) >> 6;
    s32 s2 = 1 << (w + h - 4);
    if (t4 <= 0) t4 = 1;
    if (flag == 0) {
        D_00221E20[0] = 0x10000006;
        D_00221E20[1] = 0;
        D_00221E20[2] = 0;
        D_00221E20[3] = 0x50000006;
        p = D_00221E20 + 4;
        D_00221E20 = D_00221E20 + 28;
    } else {
        p = (u32 *)buf;
    }
    func_00138E08(p, a1, t4, a2, 0, 0, 1 << w, 1 << h);
    if (flag == 0) {
        D_00221E20[0] = s2 | 0x30000000;
        D_00221E20[1] = a0;
        D_00221E20[2] = 0;
        D_00221E20[3] = s2 | 0x50000000;
        D_00221E20 = D_00221E20 + 4;
    } else {
        func_00126E20(0);
        func_00139130((u64 *)p, (u64 *)a0);
    }
}
