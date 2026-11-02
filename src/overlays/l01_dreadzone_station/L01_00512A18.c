#include "common.h"

s32 func_L01_00512A48(u8 *a0);

f32 func_L01_00512A18(u8 *a0) {
    if (!func_L01_00512A48(a0)) {
        return 0.0f;
    }
    return 1.0f;
}
