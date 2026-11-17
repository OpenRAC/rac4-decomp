/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s64 func_L01_00514C10(void *arg0) {
    s64 result = 0;

    if (*((u8 *)arg0 + 0x69) == 1) {
        s32 equal = *((u8 *)arg0 + 0x20) == 1;
        result = equal;
    }

    return result;
}
