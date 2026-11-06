#include "common.h"

// Store the byte value at +0x2D4 of the linked +0xAC object.
void func_L04_004A0DD0(u8 *object, s32 value) {
    *(u8 *)(*(u8 **)(object + 0xAC) + 724) = value;
}
