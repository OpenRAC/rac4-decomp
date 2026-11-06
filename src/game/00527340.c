#include "common.h"

extern u8 D_00171B40[];

s32 func_00527340(void *unused, s32 kind)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_00171B40[0x29 + i] != 0 && D_00171B40[0x29 + i] == kind) {
            return 1;
        }
    }
    return 0;
}
