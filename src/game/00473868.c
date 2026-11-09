#include "common.h"

extern void func_0046F2B0(void *, void *, s32, f32, s32);
extern void func_004737F0(u8 *arg0, s32 arg1, f32 fparg0);
extern void func_0047BF48(u8 *, s32, u16);

void func_00473868(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0) {
    u8 temp_v0;
    temp_v0 = (*(u8 **)(*(u32 *)(arg0 + 0x24) + (arg1 << 2) + 0x48))[0x10];
    if ((f32) temp_v0 <= fparg0) {
        fparg0 = (f32) (temp_v0 - 1);
    }
    if (fparg0 > 0.0f && fparg0 <= 11.0f) {
        func_0047BF48(arg0, arg1, (s32)fparg0);
    }
    if (arg2 <= 0) {
        func_004737F0(arg0, arg1, fparg0);
        return;
    }
    func_0046F2B0(arg0, *(void **)(*(u32 *)(arg0 + 0x24) + (arg1 << 2) + 0x48), arg1, fparg0, arg2);
    arg0[0x55] = arg0[0x55] & 0xFD;
}
