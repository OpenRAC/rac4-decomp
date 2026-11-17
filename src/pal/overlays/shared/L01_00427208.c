/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef long long s128;
extern s128 func_0047B728(s128, s128, f32);
extern s32 func_004416B0(s128 *, void *, s32, s32, s32);
s32 func_L01_00427208(void *arg0, void *arg1) {
    s128 v, t;
    s32 r;
    if (arg1) {
        t = *(s128 *)((u8 *)arg0 + 0x10);
        v = func_0047B728(t, t, -0.5f);
        r = func_004416B0(&v, (u8 *)arg1 + 0xF0, 0x1002, 0, 0) == 0;
    } else {
        r = 0;
    }
    return r;
}
