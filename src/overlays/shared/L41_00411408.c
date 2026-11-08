#include "common.h"

extern u8 D_0024A110[];
extern s32 D_002495C0[];

/* from rac3-decomp's func_L40_004224A0, constants adapted */
void func_L41_00411408(u8 *a0, s32 a1) {
    u8 b;
    *(s16 *)(a0 + 188) = a1;
    b = D_0024A110[(s16)a1];
    a0[34] = b;
    *(s32 *)(a0 + 36) = D_002495C0[a0[34]];
}
