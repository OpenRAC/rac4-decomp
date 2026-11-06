/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

extern u8 D_003AA3E8[];

/* When arg1 is zero, write 40 and return the opaque data address. */
s32 func_L01_00498F80(s32 arg0, s32 arg1, u32 *arg2) {
    if (arg1)
        return 0;
    *arg2 = 40;
    return (u32)D_003AA3E8;
}
