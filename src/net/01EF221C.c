/* cflags: @ee296 -O2 -G0 -fno-align-jumps */
#include "common.h"

extern s32 func_0015DB88(void *);
/* Dispatch when the low flag is set. */
void func_01EF221C(void *a, s32 b)
{
    if (b & 1) func_0015DB88(a);
}
