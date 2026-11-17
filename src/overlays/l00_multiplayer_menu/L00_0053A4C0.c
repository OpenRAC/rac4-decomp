/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_0053A138(s32, s32, s32, s32);

// Calls func_L00_0053A138 on each 16-byte entry of the table until an entry starting with zero.
s32 func_L00_0053A4C0(s32 *arg0) {
    s32 i;

    for (i = 0; arg0[i * 4] != 0; i++) {
        func_L00_0053A138(arg0[i * 4], arg0[i * 4 + 1], arg0[i * 4 + 2], arg0[i * 4 + 3]);
    }
    return 0;
}
