#include "common.h"

typedef struct Q {
    f32 f0, f4, f8, fC, f10, f14, f18, f1C, f20;
    u8 f24;
    char _p25[3];
    f32 f28;
    s32 f2C;
} Q;
extern f32 func_004973E0(void *, s32);
extern s32 func_00504F68(s32, s32);
extern s32 func_00504238(s32 handle, f32 a, f32 b);
extern s32 func_005058E0(u32 id, f32 a, f32 b);
extern void func_004A0D78(Q *, f32 *, f32 *, f32 *, f32 *, s32);

s32 func_004A0E20(Q *p) {
    s32 ret;
    f32 sp0, sp4, sp8, spC;
    s32 active;
    if (p->f24 == 0 && p->f28 == 0.0f) {
        return 0;
    }
    if (func_004973E0(&p->f28, p->f24) != 0.0f) {
        func_00504F68(p->f2C, p->f28 != 0.0f);
        ret = 1;
    }
    if (func_004973E0(p, 0) != 0.0f) {
        if (p->f2C != 0) {
            func_004A0D78(p, &sp0, &sp4, &sp8, &spC, 0);
            func_00504238(p->f2C, sp0, sp4);
            func_005058E0(p->f2C, sp8, spC);
        }
        ret = 1;
    }
    active = 0;
    if (p->f24 != 0 || p->f28 != 0.0f) active = 1;
    if ((u8)active == 0) {
        p->f14 = 0.0f;
        p->f18 = 0.0f;
        p->f1C = 0.0f;
        p->f20 = 0.0f;
        p->f0 = 0.0f;
    }
    return ret;
}
