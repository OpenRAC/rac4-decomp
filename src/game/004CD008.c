#include "common.h"

extern s32 func_00505B20(void);
extern s16 D_00171B76[];
extern u8 D_30EAA0[];

// Store the owner's data value at offset 0x38 and clear offset 0x3C.
void func_004CD008(void) {
    u8 *entry = D_30EAA0 + func_00505B20() * 0x64;
    *(s32 *)(entry + 0x38) = D_00171B76[0];
    *(u8 *)(entry + 0x3C) = 0;
}
