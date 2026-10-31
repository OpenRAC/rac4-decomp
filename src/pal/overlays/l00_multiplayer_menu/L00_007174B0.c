#include "common.h"

s32 func_L00_007174B0(u32 p, f32 a, f32 b) {
    *(f32*)(p + 0x10000 + 0xA68) = a;
    *(f32*)(p + 0x10000 + 0xA6C) = b;
    return 0;
}
