#include "common.h"

extern u8 D_004B7E78[];
s32 func_L00_007107C0();

s64 func_L00_007110F8(char * arg0) {
    *(s32 *)(arg0+88) = (s32)D_004B7E78;
    return func_L00_007107C0(arg0);
}
