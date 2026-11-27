#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern s32 D_399B50[];
extern s32 D_399CD0[];
extern f32 D_399E50[];
u8 D_002218C8 __attribute__((section(".sdata"))) = 0;

extern void func_L01_005A37B8(void *object, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

void func_L02_0047E8B0(u8 *arg0) {
    u8 *state = *(u8 **)(arg0 + 0xAC);
    s32 i;

    if (D_002218C8 == 0) {
        for (i = 0; i < 0x60; i++) {
            f32 f0 = (f32)(i & 1);
            f32 f1 = (f32)((i & 2) >> 1);
            D_399B50[i] = -1;
            D_399CD0[i] = 0x20FF8000;
            D_399E50[i * 2 + 1] = f0;
            D_399E50[i * 2] = f1;
        }
        D_002218C8 = 1;
    }
    func_L01_005A37B8(arg0, 4, 1, 1, 0);
    *(s128 *)(state + 0x110) = *(s128 *)(arg0 + 0x10);
    func_L01_00591BD8(arg0, 1, -1);
}
