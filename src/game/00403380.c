/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_004035D0(s32, s32, s32);
s32 func_00403380(s32 a, s32 b, s32 c) {
    if (c == 0) {
        return 0;
    }
    return func_004035D0(a, b, c);
}
