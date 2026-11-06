#include "common.h"

/* Set byte +0x1AC of the object linked at +0xAC to one. */
void func_L15_004A2140(u8 *object) {
    *(u8 *)(*(u8 **)(object + 0xAC) + 0x1AC) = 1;
}
