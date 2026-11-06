/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

extern u8 D_003A0BC0[];

/* When arg1 is zero, write 80 and return the opaque data address. */
s32 func_L01_003CC998(s32 arg0, s32 arg1, u32 *arg2) {
    if (arg1)
        return 0;
    *arg2 = 80;
    return (u32)D_003A0BC0;
}
