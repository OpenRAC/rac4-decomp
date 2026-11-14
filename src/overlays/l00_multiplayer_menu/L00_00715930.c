#include "common.h"

extern s32 func_0069DA50(s32, f32, f32);

// Calls func_0069DA50 for each non-null entry of the table at +0x6C; returns 1.
s32 func_L00_00715930(u8 *arg0, f32 arg1, f32 arg2) {
    s32 i;

    for (i = 0; i < *(s32 *)(arg0 + 0x68); i++) {
        if (((s32 *)(arg0 + 0x6C))[i] != 0) {
            func_0069DA50(((s32 *)(arg0 + 0x6C))[i], arg1, arg2);
        }
    }
    return 1;
}
