#include "common.h"

extern u8 *func_005A3780(void);

s32 func_L01_005A4648(void) {
    u8 *p;
    s32 r;

    p = func_005A3780();
    r = 0;
    if (p != NULL) {
        r = *(u8 *)(p + 0xA) != 0;
        *(u8 *)(p + 0xA) = 0;
    }
    return r;
}
