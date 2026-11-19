#include "common.h"

s64 func_L01_004B8360(u8 *object) {
    s64 result = 0;
    if (*(u8 *)(object + 0x69) == 0xA) {
        s32 t = *(u8 *)(object + 0x20) == 0x25;
        result = t;
    }
    return result;
}
