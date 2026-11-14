/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_004102F8(s32 x) {
    if (x >= 0x3FC) {
        return 6;
    }
    if (x >= 0x17E) {
        return 5;
    }
    if (x >= 0x50) {
        return 4;
    }
    return x >= 0x13 ? 3 : 2;
}
