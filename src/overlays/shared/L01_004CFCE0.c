#include "common.h"

extern s32 func_004CA908();
extern void func_004CA930();

// Latches a flag in the linked block when it is active and the check fails; returns whether it did.
s32 func_L01_004CFCE0(void *arg0) {
    u8 *obj = *(u8 **)((u8 *)arg0 + 0xAC);
    s32 r;

    if (*(s32 *)(obj + 0x2E0) == 0) {
        return 0;
    }
    r = 0;
    if (func_004CA908(arg0) == 0) {
        func_004CA930(arg0);
        *(u8 *)(obj + 0x2DF) = 1;
        r = 1;
    }
    return r;
}
