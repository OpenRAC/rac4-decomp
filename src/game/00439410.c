#include "common.h"

extern void func_004393E8();
extern s32 D_00206DC8[];
extern void func_001598F8(u32, s32, s32, s32, s32, s32, s32, void (*)(), s64);
/* Register the two adjacent entries with their shared callback. */
void func_00439410(void)
{
    func_001598F8(0xbfe87362u, 9, 0, 0, 0, 0, 0, func_004393E8, (s64)(s32)&D_00206DC8[0]);
    func_001598F8(0xbfe87362u, 9, 1, 0, 0, 0, 0, func_004393E8, (s64)(s32)&D_00206DC8[1]);
}
