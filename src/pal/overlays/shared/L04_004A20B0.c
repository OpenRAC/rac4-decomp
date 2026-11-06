#include "common.h"

/* Return whether byte +0x312 of the object linked at +0xAC is nonzero. */
s32 func_L04_004A20B0(u8 *object) {
    return *(u8 *)(*(u8 **)(object + 0xAC) + 0x312) != 0;
}
