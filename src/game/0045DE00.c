/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 D_00221388;
extern u8 D_002214D0[];

extern s32 func_0048A2F8(void *, s32, f32);

s32 func_0045DE00(void)
{
    return func_0048A2F8(D_002214D0, D_00221388, 0.0f) != 0;
}
