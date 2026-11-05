#include "common.h"

extern u8 D_00171E75[];
extern s32 D_0030E9DC[];
extern s32 D_0021FAD0;
extern void func_00466330(s32 target);

s32 func_004CC1E8(void)
{
    s32 language = D_00171E75[0];
    s32 target = D_0030E9DC[0];
    D_0021FAD0 = language;
    func_00466330(target);
    return 0;
}
