/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef long long s128;
extern s128 func_0047B728(s128, s128, f32);
extern s32 func_004416B0(s128 *, void *, s32, s32, s32);
s32 func_L01_003D4720(void *arg0, void *arg1) {
    s128 value = *(s128 *)((u8 *)arg0 + 0x10);
    s128 result = func_0047B728(value, value, -0.5f);
    return func_004416B0(&result, (u8 *)arg1 + 0xF0, 0x1002, 0, 0) == 0;
}
