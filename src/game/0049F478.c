#include "common.h"

extern void func_0049C4B0(s32, s32, s32, s32);
extern void func_0049D398(s32, s32, s32);
extern u8 D_307254[];

// Clears the flag at +0x24 of the 0x200-byte entry for arg0 and, when it was set, makes the two helper calls for it.
void func_0049F478(s32 arg0) {
    s32 temp_s0;
    u8 *temp_a3;

    temp_a3 = D_307254 + (arg0 << 9);
    if (temp_a3[0x24] != 0) {
        temp_a3[0x24] = 0;
        *(s32 *)(temp_a3 + 0x2C) = -1;
        temp_s0 = (arg0 << 6) + 0x140002;
        func_0049D398(arg0, 0, temp_s0);
        func_0049C4B0(arg0, 0, temp_s0, 0);
    }
}
