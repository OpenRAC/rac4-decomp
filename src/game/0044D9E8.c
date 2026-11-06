#include "common.h"

extern u8 D_00239540[];
extern s32 D_002212F8;
extern void func_0044AD28(void), func_0044D1B8(void *), func_0044CE08(s32, const void *, const void *, const void *, s32, s32);
void func_0044D9E8(void *unused, s32 command, const void *a, const void *b, const void *c, s32 flags, s32 mode)
{
    if (!D_00239540[0])
        func_0044AD28();
    else if (D_002212F8 != 8) {
        func_0044AD28();
        func_0044D1B8(D_00239540);
    }
    func_0044CE08(command, a, b, c, flags, mode);
}
