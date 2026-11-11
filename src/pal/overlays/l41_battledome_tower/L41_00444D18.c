/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 func_L01_006BA5F0(s32, s32, s32);

s32 func_L41_00444D18(s32 arg0, s32 arg1) {
    s32 r = func_L01_006BA5F0(arg0, 3, 0);
    return r != 0 && (r + 0xC) == arg1;
}
