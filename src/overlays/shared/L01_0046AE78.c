#include "common.h"

extern s32 D_00171B40[];
extern s32 D_359440[];
// Add the object's +0x4C amount to two running totals.
void func_L01_0046AE78(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0xAC);
    D_00171B40[0] += *(s32 *)(p + 0x4C);
    D_359440[2] += *(s32 *)(p + 0x4C);
}
