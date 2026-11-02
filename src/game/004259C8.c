/* cflags: @ee29 -O2 -G0 -fno-schedule-insns */
#include "common.h"

s32 func_004259C8(char *arg0) {
    char *p = *(char **)(arg0 + 172);
    *(s32 *)(p + 116) = 0;
    *(s32 *)(p + 112) = 0;
    *(u8 *)(arg0 + 48) = 255;
    return (s32)p;
}
