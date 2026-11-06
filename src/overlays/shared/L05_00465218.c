#include "common.h"

// Return the float at +0x174 of the linked +0xAC object.
f32 func_L05_00465218(u8 *object) {
    return *(f32 *)(*(u8 **)(object + 0xAC) + 0x174);
}
