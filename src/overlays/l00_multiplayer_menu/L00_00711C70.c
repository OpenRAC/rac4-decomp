#include "common.h"

extern s32 func_L00_0069CE38(s32, s32, s32);

// Run func_L00_0069CE38 on the handles at +0x14 and +0x5C (those that are set) with
// the two parameters; return 1 when either call returned nonzero.
s32 func_L00_00711C70(u8 *object, s32 param_a, s32 param_b) {
    s32 result = 0;
    s32 value = *(s32 *)(object + 0x14);
    if (value != 0) result = func_L00_0069CE38(value, param_a, param_b);
    value = *(s32 *)(object + 0x5C);
    if (value != 0) result |= func_L00_0069CE38(value, param_a, param_b);
    return result != 0;
}
