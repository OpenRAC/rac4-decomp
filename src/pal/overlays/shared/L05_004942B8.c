#include "common.h"

/* Set byte +0x1D3 of the object linked at +0xAC to one. */
void func_L05_004942B8(u8 *object) {
    *(u8 *)(*(u8 **)(object + 0xAC) + 0x1D3) = 1;
}
