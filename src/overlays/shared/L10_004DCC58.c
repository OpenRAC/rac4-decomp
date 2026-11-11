#include "common.h"

extern void func_005444C8(void *);
extern void func_00473A88(void *, s32, s32);

void func_L10_004DCC58(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    *(s16 *)(vars + 0x76) = (f32)*(s16 *)(vars + 0x74) * 60.0f;
    func_005444C8(arg0);
    arg0[0x30] = 0xFF;
    if (*(s32 *)(vars + 0x78) != 0) {
        func_00473A88(arg0, 1, -1);
    } else {
        func_00473A88(arg0, 2, -1);
    }
}
