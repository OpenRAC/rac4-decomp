/* cflags: -fno-delayed-branch */
#include "common.h"

/* Shift two coordinates by the 0x20 offset of the source and mirror it into the
   0x14 slot. */
void func_0050C47C(s32 a0, s32 a1, char *p, s32 a3, char *src)
{
    *(f32 *)(p + 0x4) = *(f32 *)(p + 0x4) - *(f32 *)(src + 0x20);
    *(f32 *)(p + 0xC) = *(f32 *)(p + 0xC) - *(f32 *)(src + 0x20);
    *(f32 *)(p + 0x14) = -*(f32 *)(src + 0x20);
}
