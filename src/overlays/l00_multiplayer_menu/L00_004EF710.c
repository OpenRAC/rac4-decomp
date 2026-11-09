/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_004EF030(s32, s32, s32, s32, s32, s32, s32);

s32 func_L00_004EF710(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0 == 0) {
        return -0xB;
    }
    return func_004EF030(arg0, arg1, arg2, arg3, 1, 0, arg4);
}
