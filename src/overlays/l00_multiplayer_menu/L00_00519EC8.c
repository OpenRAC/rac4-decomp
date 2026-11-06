#include "common.h"

extern u8 *func_L00_004F86B0(void);

void func_L00_00519EC8(void) {
    u8 *p;

    p = func_L00_004F86B0();
    *(s32 *)(p + 0x18C) = 0;
    *(s32 *)(p + 0x188) = 0;
}
