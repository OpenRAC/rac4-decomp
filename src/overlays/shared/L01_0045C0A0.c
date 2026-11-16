#include "common.h"

s64 func_L01_0045C0A0(u8 *object) {
    s64 result = 0;
    if (*(u8 *)(object + 0x69) == 7) {
        s32 t = *(u8 *)(object + 0x20) == 0x1B;
        result = t;
    }
    return result;
}
