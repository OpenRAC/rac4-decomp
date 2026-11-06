#include "common.h"

s32 func_00433788(s32 arg0) {
    f32 var_f2;

    var_f2 = 10.0f;
    if (arg0 < 0xA) {
        var_f2 = (f32) ((s32)((u32)arg0 * 2U)) + var_f2;
    } else {
        var_f2 = 28.0f;
        var_f2 = (f32) ((s32)((u32)arg0 - 9U)) * 0.3f + var_f2;
    }
    return (s32) var_f2;
}
