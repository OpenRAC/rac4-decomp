#include "common.h"

extern s32 func_L00_0071AF88(void *, s32);
extern void func_L00_0070C3E0(void *, s32);
extern u8 D_004BEAB0[];

s32 func_L00_0074AC98(void *arg0, s32 arg1)
{
    *(void **)((u8 *)arg0 + 88) = D_004BEAB0;
    func_L00_0070C3E0((u8 *)arg0 + 0x278, 2);
    return func_L00_0071AF88(arg0, arg1);
}
