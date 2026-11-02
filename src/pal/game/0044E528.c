#include "common.h"

extern u8 D_00239640[];
extern s32 func_0044E5B0(s32, s32, s32);
extern void func_004E88B8(s32, s32, s32);

/* Dispatches according to the flag, query result and forced fallback. */
void func_0044E528(s32 a, s32 b, s32 c, s32 d)
{
    if (D_00239640[0] == 0)
        func_004E88B8(b, c, 0);
    else if (func_0044E5B0(a, b, c) || d)
        func_004E88B8(b, c, 1);
}
