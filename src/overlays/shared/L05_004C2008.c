#include "common.h"

s64 func_L05_004C2008(u8 *arg0) {
    u8 *v1;
    s32 v;
    s64 r = 0;

    v1 = *(u8 **)(arg0 + 0xAC);
    if (*(u8 *)(v1 + 0x2C) != 0) {
        v = *(u8 *)(v1 + 0x2D) == 0;
        r = v;
    }
    return r;
}
