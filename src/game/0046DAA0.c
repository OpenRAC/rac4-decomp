#include "common.h"

extern void func_00470090(void *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern u16 *D_2213B0;

// Stores a constant 64-bit value at arg0+0x38 when D_2213B0 is null; otherwise passes arg0 and two fields of the entry at D_2213B0 + *D_2213B0 to func_00470090.
void func_0046DAA0(void *arg0) {
    u8 *entry;
    u8 b;

    if (D_2213B0 == 0) {
        *(u64 *)((u8 *)arg0 + 0x38) = (u64)0x80808000 << 23;
        return;
    }
    entry = (u8 *)D_2213B0 + *D_2213B0;
    b = entry[0x4A];
    func_00470090(arg0, *(u32 *)(entry + 0x40), b, b, 0);
}
