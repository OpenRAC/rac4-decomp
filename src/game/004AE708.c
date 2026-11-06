#include "common.h"
extern u8 D_003092A0[];
extern s32 func_00505B20(void);
extern s32 func_00498100(s32);
extern s32 func_0049A6E0(f32 *, f32);
extern void func_004AE778(void);

static inline u32 address(u32 base, u32 offset)
{
    return base + offset;
}

void func_004AE708(void)
{
    s32 context = func_00505B20();
    f32 *value = (f32 *)address(address((u32)D_003092A0, (u32)context * 0x64), 8);
    f32 target = (u8)(func_00498100(context) ^ 1);
    if (func_0049A6E0(value, target))
        func_004AE778();
}
