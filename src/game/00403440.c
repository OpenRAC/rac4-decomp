/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_003FB868(s32, s32, s32, s32, s32, s32, s32, s32);

void func_00403440(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    if (arg0) {
        func_003FB868(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}
