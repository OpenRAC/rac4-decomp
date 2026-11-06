#include "common.h"

extern s16 D_00206948[];

void func_00489498(s32 value)
{
    if (D_00206948[0x28] & 0x8000) {
        D_00206948[0x29] = value;
    }
    if (D_00206948[0x64] & 0x8000) {
        D_00206948[0x65] = value;
    }
    if (D_00206948[0x3C] & 0x8000) {
        D_00206948[0x3D] = value;
    }
}
