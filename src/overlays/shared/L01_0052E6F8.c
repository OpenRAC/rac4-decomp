#include "common.h"

extern u8 D_003B3D40[];
extern u8 D_003B3EC0[];
extern u8 D_22FEA0[];

// Store the two table addresses and the value 3 into the object at D_22FEA0.
void func_L01_0052E6F8(void) {
    u8 *obj = D_22FEA0;
    u8 *first = D_003B3D40;
    u8 *second = D_003B3EC0;

    *(s32 *)(obj + 0x18) = 3;
    *(u8 **)(obj + 0x8) = second;
    *(u8 **)(obj + 0x4) = first;
}
