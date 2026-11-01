#include "common.h"

extern s16 D_002069D0[];

void func_00489F50(s32 value)
{
    if (D_002069D0[0x28] & 0x8000) {
        D_002069D0[0x29] = value;
    }
    if (D_002069D0[0x64] & 0x8000) {
        D_002069D0[0x65] = value;
    }
    if (D_002069D0[0x3C] & 0x8000) {
        D_002069D0[0x3D] = value;
    }
}
