/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 D_00221488;
extern u8 D_002215D0[];

extern s32 func_0048ADB0(void *, s32, f32);

s32 func_0045E618(void)
{
    return func_0048ADB0(D_002215D0, D_00221488, 0.0f) != 0;
}
