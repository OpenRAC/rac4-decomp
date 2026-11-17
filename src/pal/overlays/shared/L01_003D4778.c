/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef long long s128;
extern s128 func_0047B728(s128, s128, f32);
extern void func_L00_005F4188(s32, void *, s32);
extern s32 func_004416B0(s128 *, void *, s32, s32, s32);
s32 func_L01_003D4778(void *arg0, void *arg1) {
    s128 sp0;
    s128 value = *(s128 *)((u8 *)arg0 + 0x10);
    s128 result = func_0047B728(value, value, -0.5f);
    func_L00_005F4188(*(s32 *)((u8 *)arg1 + 0x2B0), &sp0, 0);
    return func_004416B0(&result, &sp0, 0x1002, *(s32 *)((u8 *)arg1 + 0x2B0), 0) == 0;
}

