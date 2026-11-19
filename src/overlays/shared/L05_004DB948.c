#include "common.h"

s64 func_L05_004DB948(u8 *object) {
    s64 result = 0;
    if (*(u8 *)(object + 0x69) == 0x2) {
        s32 t = *(u8 *)(object + 0x20) == 0x12;
        result = t;
    }
    return result;
}
