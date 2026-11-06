/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_00408110(s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_00407448(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    return func_00408110(arg0, arg0 + 12, 1, 0, 0, arg1, arg2, arg7);
}
