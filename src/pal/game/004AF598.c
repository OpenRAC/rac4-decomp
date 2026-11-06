#include "common.h"
extern u8 D_003093A0[];
extern s32 func_00506BB8(void);
extern s32 func_00498E38(s32);
extern s32 func_0049B418(f32 *, f32);
extern void func_004AF608(void);

static inline u32 address(u32 base, u32 offset)
{
    return base + offset;
}

void func_004AF598(void)
{
    s32 context = func_00506BB8();
    f32 *value = (f32 *)address(address((u32)D_003093A0, (u32)context * 0x64), 8);
    f32 target = (u8)(func_00498E38(context) ^ 1);
    if (func_0049B418(value, target))
        func_004AF608();
}
