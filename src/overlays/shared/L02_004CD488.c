#include "common.h"

s32 func_L02_004CD488(void *p) {
    return *(u8*)(*(u32*)((u8*)p + 0xAC) + 14) != 0;
}
