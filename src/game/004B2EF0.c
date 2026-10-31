#include "common.h"

/* Clears byte 0x160 of D_3096A8, calls func_00497980(0xE), then sets the word at offset 0 to its value plus one, or to 0xD when the word at offset 8 is zero. */
extern s32 func_004983E8(s32);
extern void func_00497980(s32 arg0);
extern u8 D_3096A8[];

void func_004B2EF0(void) {
    u8 *temp_s0;
    s32 var_v0;

    if (func_004983E8(2) == 1) {
        temp_s0 = D_3096A8;
        temp_s0[0x160] = 0;
        func_00497980(0xE);
        if (*(s32 *)(temp_s0 + 8) != 0) {
            var_v0 = *(s32 *)D_3096A8 + 1;
        } else {
            var_v0 = 0xD;
        }
        *(s32 *)D_3096A8 = var_v0;
    }
}
