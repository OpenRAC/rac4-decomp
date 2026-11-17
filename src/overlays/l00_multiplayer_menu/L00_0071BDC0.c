#include "common.h"

extern void func_L00_00624B40(s32 arg0, u32 arg1);
u32 D_00220D78 = 0;

/* Resets the word at 0x254 and steps the global counter down when the byte at 0xA9 is not 1. */
void func_L00_0071BDC0(void *arg0) {
    u32 temp_a1;

    if (*(u8 *)((u8 *)arg0 + 0xA9) != 1) {
        if (D_00220D78 < 2) {
            temp_a1 = *(u32 *)((u8 *)arg0 + 0x254);
            if (temp_a1 < 2) {
                func_L00_00624B40(0, temp_a1);
            }
        }
        D_00220D78 = D_00220D78 - 1;
        *(s32 *)((u8 *)arg0 + 0x254) = -1;
    }
}
