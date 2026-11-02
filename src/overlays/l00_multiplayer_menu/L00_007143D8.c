#include "common.h"

extern u8 D_004B8D68[];
s32 func_L00_007107C0();

s64 func_L00_007143D8(char * arg0) {
    *(s32 *)(arg0+88) = (s32)D_004B8D68;
    return func_L00_007107C0(arg0);
}
