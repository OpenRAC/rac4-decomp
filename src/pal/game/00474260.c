#include "common.h"

extern void func_0047C880(void *, s32, s32);
extern void func_004740D0(void *, s32, f32);
extern void func_0046FB90(void *, void *, s32, f32, s32);

void func_00474260(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 value)
{
    u8 *entry;
    if (value > 0.0f && value <= 10.0f && (arg3 & 8) == 0) {
        func_0047C880(arg0, arg1, ((s32)value - 1) & 0xFFFF);
    }
    if (arg2 <= 0) {
        func_004740D0(arg0, arg1, value);
        return;
    }
    entry = *(u8 **)(*(u32 *)(arg0 + 0x24) + (arg1 << 2) + 0x48);
    func_0046FB90(arg0, entry, arg1, value, arg2);
    arg0[0x55] &= 0xFD;
    if ((arg3 & 0x10) != 0) {
        *(u16 *)(arg0 + 0x36) |= 4;
    } else {
        *(u16 *)(arg0 + 0x36) &= 0xFFFB;
    }
}
