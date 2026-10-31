#include "common.h"

void func_L00_0076D058(void *p) {
    u8 *state = (u8*)*(u32*)(*(u32*)0x2234a4 + 0x3c); *(u8*)(state + 0x60) = 0; *(u32*)(state + 0x64) = *(u32*)((u8*)p + 0x18);
}
