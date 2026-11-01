#include "common.h"

extern void func_004399E0();
extern s32 D_00206E48[];
extern void func_00159928(u32, s32, s32, s32, s32, s32, s32, void (*)(), s64);
/* Register the two adjacent entries with their shared callback. */
void func_00439A08(void)
{
    func_00159928(0xbfe87362u, 9, 0, 0, 0, 0, 0, func_004399E0, (s64)(s32)&D_00206E48[0]);
    func_00159928(0xbfe87362u, 9, 1, 0, 0, 0, 0, func_004399E0, (s64)(s32)&D_00206E48[1]);
}
