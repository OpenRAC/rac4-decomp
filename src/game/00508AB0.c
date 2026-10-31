#include "common.h"

extern s32 D_00220B60;
/* Calls the method at +0x14 of arg0's table (+8) with D_00220B60; on a nonzero result stores arg1 at +0x4C and returns 1, else returns 0. */
s32 func_00508AB0(void *arg0, s32 arg1) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(arg0, D_00220B60) != 0) {
        *(s32 *)(object + 0x4C) = arg1;
        return 1;
    }
    return 0;
}
