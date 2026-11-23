#include "common.h"

extern u8 D_PAL_00171228[];

s32 func_L00_00699D40(s32 requestFlag)
{
    if (D_PAL_00171228[0x12] == 0) {
        goto validate;
    }
reject:
    return 0;

validate:
    if (D_PAL_00171228[0x10] == 0) {
        goto reject;
    }
    if (*(s32 *)(D_PAL_00171228 + 0x08) != 0) {
        goto reject;
    }
    D_PAL_00171228[0x11] = 1;
    if (requestFlag != 0) {
        D_PAL_00171228[0x13] = 1;
    } else {
        D_PAL_00171228[0x14] = 1;
    }
    return 1;
}
