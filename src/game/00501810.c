/* Increment the 32-bit global by 0x100 and return its new value. */
/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern s32 D_00220ABC;

s32 func_00501810(void) {
    s32 temp_v1;

    temp_v1 = D_00220ABC + 0x100;
    D_00220ABC = temp_v1;
    return temp_v1;
}
