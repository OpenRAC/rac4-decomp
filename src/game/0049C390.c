#include "common.h"

extern u8 D_306F2C[];
extern u8 D_3070D8[];
// Clears the byte at +0x2C of one 0x34-byte record and stores 0.0 at +0x30 when the byte at +0x24 is zero.
void func_0049C390(s32 arg0, s32 arg1) {
    u8 *var;
    u8 temp;
    if (arg0 == 4) {
        var = D_306F2C + arg1 * 0x34;
    } else {
        var = D_3070D8 + (arg0 << 9) + arg1 * 0x34;
    }
    temp = var[0x24];
    var[0x2C] = 0;
    if (temp == 0) {
        *(f32 *)(var + 0x30) = (f32)temp;
    }
}
