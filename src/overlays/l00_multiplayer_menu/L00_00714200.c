#include "common.h"

extern void *func_L00_0069D9B8(s32);
f32 func_L00_00714200 (void *p) {
    void *q = func_L00_0069D9B8(*(s32*)((u8*)p + 0x5c));
    return *(f32*)((u8*)q + 0x1c);
}
