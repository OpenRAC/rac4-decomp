#include "common.h"

extern s32 D_0021EDD4;
extern u8 D_00171948[];
// Sets the timer at 0x1CC (0x20 or 0xD by mode flag), storing arg0 at 0x18 in the non-1 mode.
void func_00465AE8(s32 arg0) {
    if (D_0021EDD4 == 1) {
        u8 *a = D_00171948;
        if (*(s32 *)(a + 0x1CC) < 0) {
            *(s32 *)(a + 0x1D0) = 0;
            *(s32 *)(a + 0x1CC) = 0x20;
        }
    } else {
        u8 *b = D_00171948;
        *(s16 *)(b + 0x18) = arg0;
        *(s32 *)(b + 0x1B0) = 0;
        if (*(s32 *)(b + 0x1CC) < 0) {
            *(s32 *)(b + 0x1D0) = 0;
            *(s32 *)(b + 0x1CC) = 0xD;
        }
    }
}
