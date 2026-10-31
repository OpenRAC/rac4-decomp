#include "common.h"

extern void func_0041D6A8(void *, s32, s32, s32);

// Calls func_0041D6A8 twice on sub-blocks of the structure at arg0 (pointer at 0xAC), unless arg0 is NULL or its byte at 0x20 is 0xFE or 0xFD.
void func_0041D7F0(u8 *arg0) {
    s32 temp_s0;
    u8 temp_v1;

    if (arg0 != NULL) {
        temp_v1 = arg0[0x20];
        if (temp_v1 != 0xFE) {
            if (temp_v1 != 0xFD) {
                temp_s0 = *(s32 *)(arg0 + 0xAC);
                func_0041D6A8(arg0, temp_s0 + 0x290, temp_s0 + 0x1C, temp_s0 + 0x1E);
                func_0041D6A8(arg0, temp_s0 + 0x310, temp_s0 + 0x1D, temp_s0 + 0x1F);
            }
        }
    }
}
