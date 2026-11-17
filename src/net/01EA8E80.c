/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u32 func_01EAB1B8(s32, u32);
s32 func_01EA8E80(s32 arg0, u32 *arg1) {
    u32 v = func_01EAB1B8(arg0, arg1[1]);
    return v >= arg1[0] && v < arg1[1];
}
