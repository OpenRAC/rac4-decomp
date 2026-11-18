#include "common.h"

s64 func_L05_004F4FB0(u8 *object) {
    s64 result = 0;
    if (*(u8 *)(object + 0x69) == 5) {
        s32 t = *(u8 *)(object + 0x20) == 7;
        result = t;
    }
    return result;
}
