#include "common.h"
extern void func_0049CE90(s32, s32, s32, s32);
extern void func_005063C0(s32, u32);

static inline u32 address(u32 base, u32 offset)
{
    return base + offset;
}

void func_0049F2E8(s32 context, s32 row)
{
    func_0049CE90(context, 3, ((u32)context << 6) + address((u32)row << 1, 0x130005), 0);
    func_005063C0(((u32)context << 6) + address((u32)row << 1, 0x130006), 0x80D0D0D0U);
}
