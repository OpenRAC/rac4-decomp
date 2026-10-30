#include "common.h"

extern void func_0046E0E0(s32, u8, s32);
extern void func_0046EBD0(void *, s32);

// Releases the resource at +0x58 when set, then clears bit 0x20 of the byte at +0x55.
void func_0046EDD8(u8 *arg0) {
    if (arg0 != NULL && *(s32 *)(arg0 + 0x58) != 0) {
        func_0046EBD0(arg0, 0x70000000);
        func_0046E0E0(*(s32 *)(arg0 + 0x58), arg0[0x57], 0x70000000);
        arg0[0x55] = arg0[0x55] & 0xDF;
    }
}
