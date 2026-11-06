#include "common.h"

extern u8 D_00171BC0[];

s32 func_00528538(void *unused, s32 kind)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_00171BC0[0x29 + i] != 0 && D_00171BC0[0x29 + i] == kind) {
            return 1;
        }
    }
    return 0;
}
