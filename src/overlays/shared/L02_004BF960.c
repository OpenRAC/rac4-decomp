#include "common.h"

// Return whether the state byte at +0x20 is 4.
s32 func_L02_004BF960(u8 *object) {
    return *(u8 *)(object + 0x20) == 4;
}
