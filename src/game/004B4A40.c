#include "common.h"

extern s32 func_004983E8(s32);
extern s32 D_3096A8[];

/* Calls func_004983E8(2); on result 1 or 0xD, raises D_3096A8 to 8 and sets a flag word at offset 0x7C. */
void func_004B4A40(void) {
    s32 temp_v0;

    temp_v0 = func_004983E8(2);
    if ((temp_v0 == 1) || (temp_v0 == 0xD)) {
        if (D_3096A8[0] < 8) {
            D_3096A8[31] = 1;
            D_3096A8[0] = 8;
        }
    }
}
