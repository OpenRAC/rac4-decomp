#include "common.h"

extern s32 func_004BEF28();
extern u8 D_1F87F0[];

// Returns 0 if func_004BEF28 gives a value not above zero; otherwise bit 2 of the byte at offset 8 of the 0xC-byte entry, inverted.
s32 func_004BEFD0(void) {
    s32 temp_v0;
    s32 var_a0;
    s32 byte;

    temp_v0 = func_004BEF28();
    var_a0 = 0;
    if (temp_v0 > 0) {
        byte = D_1F87F0[temp_v0 * 0xC + 8];
        var_a0 = ((byte >> 2) & 1) ^ 1;
    }
    return var_a0;
}
