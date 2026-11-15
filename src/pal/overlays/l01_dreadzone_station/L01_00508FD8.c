/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s64 func_L01_00508FD8(void *arg0) {
    s64 result = 0;

    if (*((u8 *)arg0 + 0x69) == 2) {
        s32 equal = *((u8 *)arg0 + 0x20) == 0x11;
        result = equal;
    }

    return result;
}
