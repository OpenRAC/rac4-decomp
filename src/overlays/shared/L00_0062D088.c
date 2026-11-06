#include "common.h"

extern u8 D_0030DD68[];

void func_L00_0062D088(s32 arg0) {
    u8 *ptr;
    ptr = D_0030DD68 + (arg0 * 0x50);
    *(s32 *)(ptr + 0x40) = 2;
}
