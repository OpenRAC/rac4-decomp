#include "common.h"

extern void func_L00_007107F0(void *arg0, void *arg1);

// Copies setup values from arg1 into arg0 and calls two of arg0's virtual handlers.
void func_L00_00711690(u8 *arg0, u8 *arg1) {
    func_L00_007107F0(arg0, arg1);
    *(s32 *)(arg0 + 0x5C) = *(s32 *)(arg1 + 0x40);
    *(s32 *)(arg0 + 0x60) = *(s32 *)(arg1 + 0x44);
    arg0[0x14A4] = 1;
    (*(void (**)())(*(u8 **)(arg0 + 0x58) + 0x80))(arg0, *(s32 *)(arg1 + 0x44), *(s32 *)(arg1 + 0x48));
    (*(void (**)())(*(u8 **)(arg0 + 0x58) + 0xA4))(arg0, *(s32 *)(arg1 + 0x4C));
}
