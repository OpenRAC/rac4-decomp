#include "common.h"

extern u8 D_306F2C[];
extern u8 D_3070D8[];
// Stores arg2 at +0x2C of one 0x34-byte record and, when the byte at +0x24 is zero, also stores it as a float at +0x30.
void func_0049C328(s32 arg0, s32 arg1, s32 arg2) {
    u8 *var;
    u8 temp;

    if (arg0 == 4) {
        var = D_306F2C + arg1 * 0x34;
    } else {
        var = D_3070D8 + (arg0 << 9) + arg1 * 0x34;
    }
    temp = var[0x24];
    var[0x2C] = arg2;
    if (temp == 0) {
        *(f32 *)(var + 0x30) = (f32)(arg2 & 0xFF);
    }
}
