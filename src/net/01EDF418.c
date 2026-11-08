/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA94D0(s32 *, u64);
/* Initialize a result through the allocation helper. */
s32 func_01EDF418(u32 arg)
{
    s32 result = 0;
    func_01EA94D0(&result, (u64)arg);
    return result;
}
