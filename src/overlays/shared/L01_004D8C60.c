#include "common.h"

extern void func_00591BD8(void *, s32, s32);

void func_L01_004D8C60(void *arg0, u8 *arg1) {
    u8 state = arg1[0x20];
    u8 *vars = *(u8 **)(arg1 + 0xAC);

    if (state != 0 && state != 4 && state != 6) {
        s32 v;
        u8 kind;
        func_00591BD8(arg1, 1, -1);
        kind = arg1[0x68];
        if (kind == 2) {
            v = (s32)((f32)*(s32 *)(vars + 0x104) * 60.0f) - *(u16 *)(vars + 0x116);
        } else {
            if (kind != 5) {
                return;
            }
            v = (s32)((f32)*(s32 *)(vars + 0x104) * 60.0f);
        }
        *(s16 *)(vars + 0x114) = v;
    }
}
