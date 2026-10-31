#include "common.h"

extern void func_00499CE0(s32 arg0);
extern s32 func_00505B20(void);
extern void func_00505D30(s32 arg0);
extern u8 D_30B9D8[];

// Clears the two pending handles (+0xB20, +0xB28) of the 0xB30-byte entry chosen by func_00505B20, releasing each through func_00499CE0.
void func_004C8118(void) {
    u8 *s0;
    s32 a;

    s0 = D_30B9D8 + func_00505B20() * 0xB30;
    func_00505D30(0xF);
    a = *(s32 *)(s0 + 0xB20);
    if (a != 0) {
        func_00499CE0(a);
        *(s32 *)(s0 + 0xB20) = 0;
    }
    a = *(s32 *)(s0 + 0xB28);
    if (a != 0) {
        func_00499CE0(a);
        *(s32 *)(s0 + 0xB28) = 0;
    }
}
