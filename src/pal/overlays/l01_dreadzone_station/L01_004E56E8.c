#include "common.h"

s64 func_L01_004E56E8(u8 *object) {
    s64 result = 0;
    if (*(u8 *)(object + 0x69) == 2) {
        s32 t = *(u8 *)(object + 0x20) == 24;
        result = t;
    }
    return result;
}
