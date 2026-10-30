#include "common.h"

extern void func_00490400(s32);
extern void func_004D3528(void);
extern u8 D_1EE600[];
// Calls func_00490400 on each 0x5C0-byte entry of D_1EE600 over 0x2E00 bytes, then calls func_004D3528.
void func_00490878(void) {
    s32 var_s0 = (s32)D_1EE600;
    s32 end = var_s0 + 0x2E00;
    do {
        func_00490400(var_s0);
        var_s0 += 0x5C0;
    } while (var_s0 < end);
    func_004D3528();
}
