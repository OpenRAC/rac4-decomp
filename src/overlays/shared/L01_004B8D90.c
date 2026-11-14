#include "common.h"

extern s32 func_L00_005F6AE0(void *, s32, s32, s32, s32, s32, f32);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

/* On message 4, calls func_L00_005F6AE0 with zero float and arguments, then sets state 0xB or 0x1E by the byte at +0x60D. Always returns 1. */
s32 func_L01_004B8D90(u8 *obj, s32 msg) {
    u8 *s1 = *(u8 **)(obj + 0xAC);

    if (msg == 4) {
        func_L00_005F6AE0(obj, 0xB, 0, 0, 0, 0, 0.0f);
        if (s1[0x60D] != 0) {
            func_L01_00591BD8(obj, 0xB, -1);
        } else {
            func_L01_00591BD8(obj, 0x1E, -1);
        }
    }
    return 1;
}
