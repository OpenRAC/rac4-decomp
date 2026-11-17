#include "common.h"

extern void func_L00_005C4E38(s32, s32, s32, s32, s32);
extern void func_L00_005C5278(s32 x, s32 y);
extern void func_L00_00679210(s32, u64, s32);

/* Sets up a region sized from arg0 + arg1 and issues a series of calls. */
void func_L00_005AD5F0(s32 arg0, s32 arg1, s32 arg2)
{
    s32 n = arg0 + arg1;
    if (n > 0x10) {
        n = 0x10;
    }
    func_L00_005C4E38(arg0, arg1, ((0x400000 - (4 << n)) >> 13) << 13, 1, arg2);
    func_L00_00679210(0x47, 0x30000, 0);
    func_L00_00679210(0x42, 0x8000000044ULL, 0);
    func_L00_005C5278(0x100, 0x100);
    func_L00_00679210(0x42, 0x8000000044ULL, 0);
}
