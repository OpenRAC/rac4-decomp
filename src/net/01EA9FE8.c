/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_00126BB0(s32);

/* Returns 2 for null, otherwise maps the helper result to a status. */
s32 func_01EA9FE8(void *object)
{
    if (object == 0)
        return 2;
    return func_00126BB0(*(s32 *)((char *)object + 0xC)) == -1 ? 0x384 : 0;
}
