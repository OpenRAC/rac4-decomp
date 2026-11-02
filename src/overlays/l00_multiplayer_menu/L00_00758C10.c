#include "common.h"

extern u8 D_004BFA58[];
s32 func_L00_0071AF88();

s64 func_L00_00758C10(char * arg0) {
    *(s32 *)(arg0+88) = (s32)D_004BFA58;
    return func_L00_0071AF88(arg0);
}
