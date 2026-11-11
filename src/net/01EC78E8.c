/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

s32 func_01EC78E8(u32 arg0, u8 arg1, u8 arg2)
{
    return arg0 < 2 && arg1 != 0 && (arg1 >= 2 || arg2 >= 9);
}
