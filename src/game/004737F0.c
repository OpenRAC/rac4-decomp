#include "common.h"

extern void func_0046F2B0(void *, void *, s32, s32, f32);

// Clamp the float argument to one less than a sub-object's count byte, call the helper, then clear bit 1 of the flags byte.
void func_004737F0(u8 *arg0, s32 arg1, f32 fparg0) {
    u8 *temp_a1;
    u8 temp_v0;
    f32 var_f12;
    var_f12 = fparg0;
    temp_a1 = *(u8 **)(*(u32 *)(arg0 + 0x24) + (arg1 << 2) + 0x48);
    temp_v0 = temp_a1[0x10];
    if ((f32) temp_v0 <= var_f12) {
        var_f12 = (f32) (temp_v0 - 1);
    }
    func_0046F2B0(arg0, temp_a1, arg1, 0, var_f12);
    arg0[0x55] = arg0[0x55] & 0xFD;
}
