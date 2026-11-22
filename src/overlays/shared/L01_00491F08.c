#include "common.h"
extern s32 func_004534D0(void *);
extern void func_L01_005ABDE8(void *, f32, f32, f32);
s32 func_L01_00491F08(u8 *obj, s32 kind) {
    u8 *a = *(u8 **)(obj + 0xAC);
    f32 f1, f0;
    switch (kind) {
    case 0:
        *(s32 *)(obj + 0x98) = 0;
        *(s32 *)(a + 0x4AC) = 5;
        a[0x2B1] = 0;
        *(s32 *)(a + 0xF0) |= 0x80;
        break;
    case 1:
        if (func_004534D0(a + 0x4AC) != 0) {
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
        }
        f1 = *(f32 *)(obj + 0x70);
        f0 = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
        *(f32 *)(obj + 0x70) = (f1 < f0) ? f1 + 0.005f : f0;
        func_L01_005ABDE8(obj, 0.0f, 27.0f, 31.0f);
        break;
    case 4: {
        u8 *b = *(u8 **)(obj + 0x24);
        *(s32 *)(obj + 0x98) = *(s32 *)(b + 0x10);
        *(f32 *)(obj + 0x70) = *(f32 *)(b + 0x24);
        a[0x2B1] = 1;
        *(s32 *)(a + 0x13C) = 0;
        *(s32 *)(a + 0xF4) |= 0x800;
        *(s32 *)(a + 0xF0) &= ~0x80;
        break;
    }
    }
    return 1;
}
