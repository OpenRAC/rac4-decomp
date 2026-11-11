/* cflags: @ee296 -O2 -G0 -fno-align-jumps */
#include "common.h"

extern s32 func_01EF0B78(s32);
/* Forward the first argument when bit zero is set. */
void func_01EF0B14(s32 a, s32 b)
{
    if (b & 1) func_01EF0B78(a);
}
