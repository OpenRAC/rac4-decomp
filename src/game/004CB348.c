#include "common.h"

extern u8 D_00171DF5[];
extern s32 D_0030E9DC[];
extern s32 D_0021FA30;
extern void func_00465AE8(s32 target);

s32 func_004CB348(void)
{
    s32 language = D_00171DF5[0];
    s32 target = D_0030E9DC[0];
    D_0021FA30 = language;
    func_00465AE8(target);
    return 0;
}
