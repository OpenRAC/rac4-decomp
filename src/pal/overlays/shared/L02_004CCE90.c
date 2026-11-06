#include "common.h"

// Store the byte value at +0x20F of the linked +0xAC object.
void func_L02_004CCE90(u8 *object, s32 value) {
    *(u8 *)(*(u8 **)(object + 0xAC) + 527) = value;
}
