/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011C220(u8 *arg0);

// Release the buffer at +0x20 if active, clear the active flag; 1 if +0x10 set.
s32 func_L00_0053BF08(s32 *arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (arg0[4] == 0) {
        return 1;
    }
    if (arg0[3] != 0 && arg0[8] != 0) {
        func_0011C220((u8 *)arg0[8]);
        arg0[8] = 0;
    }
    arg0[3] = 0;
    return 1;
}
