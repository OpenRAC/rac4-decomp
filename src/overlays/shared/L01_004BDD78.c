/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u32 D_00171C14;

s32 func_L01_004BDD78(void) {
    u32 v = D_00171C14 & 0x04000000;

    return (s32)v > 0;
}
