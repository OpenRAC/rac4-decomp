#include "common.h"

/* Returns whether the argument is an ASCII decimal digit. */
s32 func_01EA88A0(s32 arg0) {
    s32 below = arg0 < 0x30;
    s32 upper = arg0 < 0x3A;
    if (upper && !below) return 1;
    return 0;
}
