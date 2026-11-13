#include "common.h"
#include "pal/record_001F1480.h"

/* Forward the four observed arguments when the table entry allows it. */
s32 func_0045E288(s16 arg0, s16 arg1, u32 arg2, s32 arg3)
{
    s32 value;

    if (D_001F1480[arg1].f0 != 0)
        value = 0;
    else
        value = func_0045E2D8(arg0, arg1, arg2, arg3);
    return value;
}
