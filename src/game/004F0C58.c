#include "common.h"

extern s32 func_0012D420();
extern s32 func_0012D470();

// Set bit 0x10000 in the register at 0x1000F590, store arg0 at 0x1000B400, then clear the bit again.
void func_004F0C58(s32 arg0) {
    func_0012D420();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B400 = arg0;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    func_0012D470();
}
