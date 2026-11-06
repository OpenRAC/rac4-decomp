#include "common.h"
extern s32 D_0021EDD4;
s32 D_0021EDD8 = 0;
extern u8 D_0020FF08[];
s32 func_004E7388(s32 feature)
{
    if (feature == 16) {
        if (D_0021EDD4 != 0 || D_0021EDD8 != 1)
            return 0;
    }
    return *(const u8 *)((u32)D_0020FF08 + (u32)feature) != 0;
}
