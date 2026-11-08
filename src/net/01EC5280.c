/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

s32 func_01EC5150(s32);
s32 func_01EC5248(void);

s32 func_01EC5280(void)
{
    s32 x = func_01EC5248();

    if (func_01EC5150(x) == 0) {
        return 0;
    }
    return x;
}
