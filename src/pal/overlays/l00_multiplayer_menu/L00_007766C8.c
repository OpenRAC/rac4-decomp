#include "common.h"

void func_L00_007766C8(void *p) {
    u8 *state = (u8*)*(u32*)(*(u32*)0x2234a4 + 0x4c); *(u8*)(state + 0x1c) = 0; *(u32*)(state + 0x20) = *(u32*)((u8*)p + 0x18);
}
