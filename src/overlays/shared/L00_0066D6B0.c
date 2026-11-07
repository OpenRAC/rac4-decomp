#include "common.h"

extern u8 *func_L00_005BD3C0(s32);

s32 func_L00_0066D6B0(s16 arg0, s32 arg1) {
    u8 *p;

    p = func_L00_005BD3C0(arg0);
    if (p != NULL) {
        *(u16 *)(p + 0xC) = arg1;
    }
    return 1;
}
