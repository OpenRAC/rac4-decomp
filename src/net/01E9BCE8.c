/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01E9B788(s32, s32, s32 *, s32, s32);
s32 func_01E9BCE8(s32 arg0, s32 *arg1, s32 arg2, s32 arg3) {
    arg1[0] = arg2;
    arg1[1] = arg3;
    if (func_01E9B788(arg0, 0xF, arg1, 8, 4) < 0) {
        return -0x21E;
    }
    return arg1[0];
}
