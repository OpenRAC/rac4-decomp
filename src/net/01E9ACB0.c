/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0011D878(s32, s32, s32, s32);

s32 func_01E9ACB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    if (*(s32 *)(arg3 + 0x28) == 3) {
        return func_0011D878(arg0, arg1, arg2, arg4 + 0x17C);
    }
    if (*(s32 *)(arg3 + 0x28) == 4) {
        return func_0011D878(arg0, arg1, arg2, arg4 + 8);
    }
}
