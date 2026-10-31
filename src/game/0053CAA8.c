#include "common.h"

extern void func_00453718();

// Adds arg2 to the byte at +0x54, after calling func_00453718 on the pointer at +0x54 + 0xC, then updates the word at +0 when the field at bits 4-9 is below the new byte.
void func_0053CAA8(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_a0;

    func_00453718(arg0 + (arg0[0x54] + 0xC));
    arg0[0x54] = arg0[0x54] + arg2;
    temp_v0 = arg0[0x54];
    temp_a0 = *(s32 *)arg0;
    temp_v0_2 = temp_v0 & 0xFF;
    if ((((u32)temp_a0 >> 4) & 0x3F) < temp_v0_2) {
        *(s32 *)arg0 = (temp_a0 & -0x3F1) | ((temp_v0_2 & 0x3F) << 4);
    }
}
