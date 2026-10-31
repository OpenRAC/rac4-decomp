#include "common.h"

s32 func_L00_007174C8(u32 p, u32 x) {
    *(u32*)(p + 0x10000 + 0xE90) = x;
    return 1;
}
