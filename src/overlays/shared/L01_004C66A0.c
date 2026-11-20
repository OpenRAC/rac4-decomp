#include "common.h"

extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;

void func_L01_004C66A0(u8 *arg0, Vec4 *arg1, Vec4 *arg2, s32 arg3, f32 fparg0) {
    u8 *v1;

    *(Vec4 *)(arg0 + 0x10) = *arg1;
    v1 = *(u8 **)(arg0 + 0xAC);
    *(Vec4 *)(v1 + 0x10) = *arg2;
    *(f32 *)(v1 + 0x4) = fparg0;
    *(s32 *)(v1 + 0x0) = 0x64;
    *(s32 *)(v1 + 0x8) = arg3;
    *(u16 *)(arg0 + 0x34) &= 0xFFF9;
    func_L01_00591BD8(arg0, 3, -1);
}
