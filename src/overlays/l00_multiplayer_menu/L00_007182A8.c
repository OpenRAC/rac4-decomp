#include "common.h"

extern u8 D_004B9A28[];
s32 func_L00_007107C0();

s64 func_L00_007182A8(char * arg0) {
    *(s32 *)(arg0+88) = (s32)D_004B9A28;
    return func_L00_007107C0(arg0);
}
