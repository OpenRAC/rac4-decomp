/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EC98E8(s32, s32, s32, s32);
extern s32 func_01ECB358(s32, s32, s32);

s32 func_01ECC7E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    return func_01ECB358(func_01EC98E8(arg0, arg1, arg2, arg3), 0, 0);
}
