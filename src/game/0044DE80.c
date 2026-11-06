#include "common.h"

extern u8 D_00239540[];
extern s32 func_0044DF08(s32, s32, s32);
extern void func_004E7990(s32, s32, s32);

/* Dispatches according to the flag, query result and forced fallback. */
void func_0044DE80(s32 a, s32 b, s32 c, s32 d)
{
    if (D_00239540[0] == 0)
        func_004E7990(b, c, 0);
    else if (func_0044DF08(a, b, c) || d)
        func_004E7990(b, c, 1);
}
