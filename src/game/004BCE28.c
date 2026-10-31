#include "common.h"

extern s32 func_00505B20(void);
extern u8 D_30A6F0[];

// Finds the 0x18-byte entry for the value from func_00505B20 in block D_30A6F0 and returns whether its state word is not 1.
s32 func_004BCE28(s32 arg0) {
    s32 var_s0;
    u8 *temp_v1;
    u8 *base;
    u8 *var_v0;

    var_s0 = arg0;
    base = (u8 *)(func_00505B20() * 0x534 + (s32)D_30A6F0);
    temp_v1 = base + 0x4C8;
    if (var_s0 >= 0) {
        var_v0 = *(u8 **)(temp_v1 + 0x34) + var_s0 * 0x18;
    } else {
        var_s0 = *(s32 *)(temp_v1 + 0x54);
        if (var_s0 < 0) {
            var_v0 = 0;
        } else {
            var_v0 = *(u8 **)(temp_v1 + 0x34) + var_s0 * 0x18;
        }
    }
    return *(s32 *)(*(u8 **)(var_v0 + 8) + 8) != 1;
}
