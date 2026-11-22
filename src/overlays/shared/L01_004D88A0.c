#include "common.h"
extern void func_L01_005A37B8(void *, s32, s32, s32, s32);
extern s32 func_L01_005864A0(void *);
extern void func_00473A88(void *, s32, s32);
s32 func_L01_004D88A0(u8 *arg0) {
    u8 *s;
    if (arg0[0x20] != 0) {
        return 0;
    }
    s = *(u8 **)(arg0 + 0xAC);
    func_L01_005A37B8(arg0, 5, 1, 1, 0);
    *(s16 *)(s + 0x114) = 0;
    *(s16 *)(s + 0x116) = 0;
    *(f32 *)(s + 0x118) = *(f32 *)(arg0 + 0xF8);
    *(s32 *)(s + 0x11C) = 0;
    *(s32 *)(s + 0x64) = 0;
    *(f32 *)(s + 0x120) = 1.0f;
    if (func_L01_005864A0(arg0) != 0) {
        s[0x109] = 1;
    }
    if (s[0x10B] != 0) {
        if (s[0x109] != 0) {
            *(s16 *)(s + 0x116) = (s16)((f32)*(s32 *)(s + 0x104) * 60.0f);
            func_00473A88(arg0, 2, -1);
            return 1;
        }
    } else if (s[0x109] != 0) {
        func_00473A88(arg0, 4, -1);
        return 1;
    }
    if (s[0x10A] != 0) {
        func_00473A88(arg0, 6, -1);
    } else {
        func_00473A88(arg0, 5, -1);
    }
    return 1;
}
