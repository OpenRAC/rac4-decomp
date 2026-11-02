#include "common.h"

extern u8 D_004B7C58[];
s32 func_L00_007107C0();

s64 func_L00_00710D08(char * arg0) {
    *(s32 *)(arg0+88) = (s32)D_004B7C58;
    return func_L00_007107C0(arg0);
}
