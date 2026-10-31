#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern void func_00474368(u8 *, s32, s32);

// Unless the object is in state 2, sets it to state 2 and stores 0.02 at +0x50 of its +0xAC block;
// then copies the 16 bytes at arg1 to +0x10 of that block.
void func_L15_004CDDA8(u8 *arg0, u128 *arg1) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    if (arg0[0x20] != 2) {
        func_00474368(arg0, 2, -1);
        *(f32 *)(vars + 0x50) = 0.020000001f;
    }
    *(u128 *)(vars + 0x10) = *arg1;
}
