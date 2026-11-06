/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_003FB530(s32);

s32 func_004033B0(s32 value)
{
    return func_003FB530(value == 0 ? 1 : value);
}
