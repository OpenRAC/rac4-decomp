/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

// Identifies status values other than the three excluded codes.
s32 func_01EC52B8(s32 arg0) {
    s32 result = 0;
    if (arg0 != 0 && arg0 != -0x54) {
        result = arg0 != -0x6c;
    }
    return result;
}
