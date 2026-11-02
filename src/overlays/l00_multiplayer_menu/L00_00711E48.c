#include "common.h"

extern s32 func_L00_0069DA50(s32, f32, f32);

// Run func_L00_0069DA50 on the handles at +0x14 and +0x5C (those that are set) with
// x and y; return 1 when either call returned nonzero.
s32 func_L00_00711E48(u8 *object, f32 x, f32 y) {
    s32 result = 0;
    s32 value = *(s32 *)(object + 0x14);
    if (value != 0) result = func_L00_0069DA50(value, x, y);
    value = *(s32 *)(object + 0x5C);
    if (value != 0) result |= func_L00_0069DA50(value, x, y);
    return result != 0;
}
