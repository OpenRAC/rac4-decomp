/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

extern s32 D_1BCC28[];
extern s32 func_00126B10(s32);

/* If the slot at +0x30 is set and func_00126B10 echoes it, set the flag at +0x3C and return 0; otherwise return 0x80000000. */
s32 func_00154BA8(void) {
    if (D_1BCC28[12] == 0) {
        return 0x80000000;
    }
    if (func_00126B10(D_1BCC28[12]) == D_1BCC28[12]) {
        D_1BCC28[15] = 1;
        return 0;
    }
    return 0x80000000;
}
