#include "common.h"

void func_L00_00775720(void *p) {
    u8 *state = (u8*)*(u32*)(*(u32*)0x2234a4 + 0x44); *(u8*)(state + 0xc) = 0; *(u32*)(state + 0x10) = *(u32*)((u8*)p + 0x18);
}
