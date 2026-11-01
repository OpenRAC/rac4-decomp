#include "common.h"

// Store the byte value at +0x1D4 of the linked +0xAC object.
void func_L05_00465208(u8 *object, s32 value) {
    *(u8 *)(*(u8 **)(object + 0xAC) + 0x1D4) = value;
}
