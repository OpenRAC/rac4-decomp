#include "common.h"

s64 func_L01_004B3D18(u8 *object) {
    s64 result = 0;
    if (*(u8 *)(object + 0x69) == 0x9) {
        s32 t = *(u8 *)(object + 0x20) == 0x1A;
        result = t;
    }
    return result;
}
