#include "common.h"

/* Clears a field of the per-index record in D_31D100 and calls two functions with it. */
extern void func_00499CE0(s32);
extern s32 func_00505B20(void);
extern void func_00505D30(s32 arg0);
extern u8 D_31D100[];

void func_004D64A0(void) {
    u8 *temp_s0;

    temp_s0 = D_31D100 + func_00505B20() * 0x528;
    func_00505D30(0xF);
    func_00499CE0(*(s32 *)(temp_s0 + 8));
    *(s32 *)(temp_s0 + 8) = 0;
}
