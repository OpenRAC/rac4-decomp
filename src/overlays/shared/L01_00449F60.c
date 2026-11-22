#include "common.h"

extern s32 D_0021DDB8;
extern void func_L01_0044AA78(void *, s32, f32);

s32 func_L01_00449F60(void *obj) {
    u8 *p = *(u8 **)((u8 *)obj + 0xAC);
    s32 n;
    s32 a;
    s32 b;
    s32 m;
    n = *(s16 *)(p + 0x138);
    if (n == -1) return 0;
    a = (s32)(n * *(f32 *)(p + 0x130));
    b = (s32)(n * *(f32 *)(p + 0x134));
    m = D_0021DDB8 % n;
    if (m >= a && m < b) {
        func_L01_0044AA78(obj, 4, 0.0f);
        return 1;
    }
    if ((m < a && a - 90 < m) || (b < m && *(s16 *)(p + 0x138) + a - 90 < m)) {
        if (D_0021DDB8 % 30 < 15) {
            *(s32 *)((u8 *)obj + 0x60) = 0xFF0000FF;
        }
    }
    return 0;
}
