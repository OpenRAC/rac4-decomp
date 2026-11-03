#include "common.h"

extern u8 D_00239640[];
extern s32 D_002213F8;
extern void func_0044B3D0(void), func_0044D860(void *), func_0044D4B0(s32, const void *, const void *, const void *, s32, s32);
void func_0044E090(void *unused, s32 command, const void *a, const void *b, const void *c, s32 flags, s32 mode)
{
    if (!D_00239640[0])
        func_0044B3D0();
    else if (D_002213F8 != 8) {
        func_0044B3D0();
        func_0044D860(D_00239640);
    }
    func_0044D4B0(command, a, b, c, flags, mode);
}
