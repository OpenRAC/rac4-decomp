#include "common.h"

extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern s16 D_1F1400[];

/* Clears the shared counters in D_1F1400 and sets the object's state to 1 when its first flag is clear. */
s32 func_L01_00454E60(u8 *arg0) {
    u8 *p;

    if (arg0[0x20] != 0) {
        return 0;
    }
    arg0[0x30] = 0xFF;
    *(u8 *)(*(u8 **)(arg0 + 0xAC) + 0x3E) = 1;
    p = (u8 *)D_1F1400;
    *(s16 *)(p + 0x1CD4) = 0;
    *(s16 *)(p + 0x1D1C) = 0;
    *(s16 *)(p + 0x49F8) = 0;
    *(s16 *)(p + 0x1D34) = 0;
    *(s16 *)(p + 0x4F5C) = 0;
    *(s16 *)(p + 0x4C50) = 0;
    *(s16 *)(p + 0x1D4C) = 0;
    *(s16 *)(p + 0x1D64) = 0;
    *(s16 *)(p + 0x4CE0) = 0;
    *(s16 *)(p + 0x1D70) = 0;
    func_L01_00591BD8(arg0, 1, 0);
    return 1;
}
