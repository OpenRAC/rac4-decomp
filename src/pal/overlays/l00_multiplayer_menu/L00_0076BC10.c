#include "common.h"

void func_L00_0076BC10(void *p) {
    u8 *state = (u8*)*(u32*)(*(u32*)0x2234a4 + 0x38); *(u8*)(state + 0x14) = 0; *(u32*)(state + 0x18) = *(u32*)((u8*)p + 0x18);
}
