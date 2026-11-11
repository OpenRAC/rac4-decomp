/* cflags: @ee296 -O2 -G0 -fno-align-jumps */
#include "common.h"

extern void func_01EE407C(void *);
/* Forward the object member when present. */
void func_01EE38C4(void **p)
{
    if (p) func_01EE407C(p[8]);
}
