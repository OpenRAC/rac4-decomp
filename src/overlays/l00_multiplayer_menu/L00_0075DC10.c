#include "common.h"

extern u8 D_004BFCC8[];
s32 func_L00_0071AF88();

s64 func_L00_0075DC10(char * arg0) {
    *(s32 *)(arg0+88) = (s32)D_004BFCC8;
    return func_L00_0071AF88(arg0);
}
