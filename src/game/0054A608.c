#include "common.h"

extern void func_00549DC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0054A7E0(s32, s32);

/* Validates the value from func_0054A7E0 (1 to 8), clears the byte at +0xA3C of entry arg1, and calls func_00549DC0 when arg2 is set. */
s32 func_0054A608(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_0054A7E0(arg0, arg1);
    if ((u32)(temp_v0 - 1) >= 8U) {
        return 0;
    }
    *(u8 *)((u32)arg0 + (arg1 * 0x44) + 0xA3C) = 0;
    if (arg2 != 0) {
        func_00549DC0(arg0, temp_v0, -1, 0);
    }
    return 1;
}
