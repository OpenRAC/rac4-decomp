#include "common.h"

s64 func_L01_005129F0(u8 *object) {
    s64 result = 0;
    if (*(u8 *)(object + 0x69) == 0x1) {
        s32 t = *(u8 *)(object + 0x20) == 0x1;
        result = t;
    }
    return result;
}
