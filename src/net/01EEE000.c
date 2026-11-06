/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Returns whether the input is an ASCII alphabetic character.
s32 func_01EEE000(u32 x) {
    if (x - 0x41U >= 26U && x - 0x61U >= 26U) return 0;
    return 1;
}
