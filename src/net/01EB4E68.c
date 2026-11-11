/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u32 func_01EA9140(char *);
/* Parse a value into the output word. */
s32 func_01EB4E68(u32 *out, char *p)
{
    *out = func_01EA9140(p);
    return 0;
}
