#include "common.h"

s32 func_0012CB20(void *arg0);
void func_00159EC0();
extern u8 D_00172160[];
extern u8 D_0021EF20[];

/* Calls func_0012CB20 on D_0021EF20; on success sets flag 0x264 and calls func_00159EC0, otherwise clears it. Returns the flag. */
u8 func_00460180(void) {
    if (func_0012CB20(D_0021EF20) >= 0) {
        D_00172160[0x264] = 1;
        func_00159EC0();
    } else {
        D_00172160[0x264] = 0;
    }
    return D_00172160[0x264];
}
