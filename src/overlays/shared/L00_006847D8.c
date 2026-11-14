#include "common.h"

extern s32 D_00335EE0[];
extern s32 D_00335F20[];
extern s32 func_001588F8(s32 arg0);
s32 D_00220260 = 0;

// Return 1 when the mapped value for an in-range index is not -1 and func_001588F8 reports it, else 0.
s32 func_L00_006847D8(s32 arg0) {
    s32 value;
    s32 result;
    if (arg0 < 0 || arg0 >= D_00220260) {
        return 0;
    } else {
        value = D_00335F20[D_00335EE0[arg0]];
        result = 0;
        if (value != -1) {
            result = func_001588F8(value) != 0;
        }
        return result;
    }
}
