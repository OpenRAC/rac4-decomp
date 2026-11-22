#include "common.h"

extern f32 func_00453BF8(f32, f32);
extern void func_00473A88(void *, s32, s32);

s32 func_L01_00449E28(void *obj) {
    u8 *p = *(u8 **)((u8 *)obj + 0xAC);
    if (p[0x105] != 0) return 0;
    if (*((u8 *)obj + 0x20) == 8) return 1;
    if (func_00453BF8(*(f32 *)((u8 *)obj + 0xF0), 3.1415927f) > 0.017453292f) {
        func_00473A88(obj, 8, -1);
        return 1;
    }
    p[0x105] = 1;
    return 0;
}
