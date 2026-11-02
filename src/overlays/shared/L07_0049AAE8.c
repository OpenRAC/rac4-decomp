#include "common.h"

// Return whether the state byte at +0x69 is 1.
s32 func_L07_0049AAE8(u8 *object) {
    return *(u8 *)(object + 0x69) == 1;
}
