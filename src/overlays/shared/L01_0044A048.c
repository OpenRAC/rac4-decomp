#include "common.h"

extern s32 D_0021DDB8;
extern void func_L01_0044AA78(void *, s32, f32);

s32 func_L01_0044A048(void *obj) {
    u8 *p = *(u8 **)((u8 *)obj + 0xAC);
    s32 n;
    s32 a;
    s32 b;
    s32 m;
    if (*(s16 *)(p + 0xF0) != 4) return 0;
    n = *(s16 *)(p + 0x138);
    if (n == -1) return 0;
    a = (s32)(n * *(f32 *)(p + 0x130));
    b = (s32)(n * *(f32 *)(p + 0x134));
    m = D_0021DDB8 % n;
    if (m < a || m >= b) {
        func_L01_0044AA78(obj, *(s16 *)(p + 0x13A) == -1 ? 0 : 5, 0.0f);
        return 1;
    }
    return 0;
}
