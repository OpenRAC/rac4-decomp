#include "common.h"

s64 func_L05_004DD4D0(u8 *object) {
    s64 result = 0;
    if (*(u8 *)(object + 0x69) == 2) {
        s32 t = *(u8 *)(object + 0x20) == 18;
        result = t;
    }
    return result;
}
