#include "common.h"

extern s32 func_004534D0(void *);
extern void func_L01_005ABDE8(void *, f32, f32, f32);

s32 func_L01_0043AE40(u8 *obj, s32 k) {
    u8 *c = *(u8 **)(obj + 0xAC);
    f32 f2;
    f32 f0;
    u8 *t;
    switch (k) {
    case 0:
        *(s32 *)(obj + 0x98) = 0;
        *(s32 *)(c + 0x4AC) = 5;
        c[0x2B1] = 0;
        *(s32 *)(c + 0xF0) |= 0x80;
        break;
    case 1:
        if (func_004534D0(c + 0x4AC) != 0) {
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
        }
        f2 = *(f32 *)(obj + 0x70);
        f0 = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 1.25f;
        if (f2 < f0) {
            *(f32 *)(obj + 0x70) = f2 + 0.005f;
        } else {
            *(f32 *)(obj + 0x70) = f0;
        }
        func_L01_005ABDE8(obj, 0.0f, 19.0f, 31.0f);
        break;
    case 4:
        t = *(u8 **)(obj + 0x24);
        *(s32 *)(obj + 0x98) = *(s32 *)(t + 0x10);
        *(f32 *)(obj + 0x70) = *(f32 *)(t + 0x24) * 1.25f;
        c[0x2B1] = 1;
        *(s32 *)(c + 0x13C) = 0;
        *(s32 *)(c + 0xF4) |= 0x800;
        *(s32 *)(c + 0xF0) &= ~0x80;
        break;
    }
    return 1;
}
