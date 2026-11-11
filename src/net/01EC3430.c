/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

extern s32 func_01EA8FD8(s32, void *);
/* Map the helper result to status one or two. */
s32 func_01EC3430(void)
{
    s32 value = func_01EA8FD8(0, 0);
    s32 result = 1;
    if (value) result = 2;
    return result;
}
