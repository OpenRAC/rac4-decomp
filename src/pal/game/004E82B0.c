#include "common.h"
extern s32 D_0021EE54;
s32 D_0021EE58 = 0;
extern u8 D_0020FF88[];
s32 func_004E82B0(s32 feature)
{
    if (feature == 16) {
        if (D_0021EE54 != 0 || D_0021EE58 != 1)
            return 0;
    }
    return *(const u8 *)((u32)D_0020FF88 + (u32)feature) != 0;
}
