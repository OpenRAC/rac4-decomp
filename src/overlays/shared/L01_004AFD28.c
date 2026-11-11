#include "common.h"

extern void func_00473A88(void *, s32, s32);

void func_L01_004AFD28(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    if (*(s32 *)(vars + 0x10) > 0) {
        u8 flags;
        func_00473A88(arg0, 2, -1);
        flags = arg0[0xBE];
        if ((flags ^ 1) & 1) {
            arg0[0xBE] = flags | 1;
        }
        *(s16 *)(vars + 0xC) = (f32)*(s32 *)(vars + 0x10) * 60.0f;
    } else {
        func_00473A88(arg0, 1, -1);
    }
}
