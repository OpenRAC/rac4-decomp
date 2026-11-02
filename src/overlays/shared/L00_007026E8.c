#include "common.h"

extern void *func_L00_00702480(s32 arg0);
s32 func_007028C8(s32 arg0);

/* Returns 0 for a zero arg; else passes the pointer from func_L00_00702480 plus 0x20 to func_007028C8. */
s32 func_L00_007026E8(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return func_007028C8((s32)((u8 *)func_L00_00702480(arg0) + 0x20));
}
