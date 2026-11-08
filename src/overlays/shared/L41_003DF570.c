/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 func_L01_006B5028(s32, s32, s32);

s32 func_L41_003DF570(s32 arg0, s32 arg1) {
    s32 r = func_L01_006B5028(arg0, 0xA, 0);
    return r != 0 && (r + 0xC) == arg1;
}
