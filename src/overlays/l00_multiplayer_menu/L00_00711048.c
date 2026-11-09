#include "common.h"

extern u8 *func_L00_0069D9B8(s32);

s32 func_L00_00711048(u8 *arg0, s32 arg1) {
    return *(f32 *)(func_L00_0069D9B8(arg1 | *(s32 *)(arg0 + 0x10)) + 0x1C) * 512.0f;
}
