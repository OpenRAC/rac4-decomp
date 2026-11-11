/* cflags: @ee296 -O1 -G0 */
#include "common.h"

/* Store in the first empty entry among 128 words. */
s32 func_01EF2D88(s32 *p, s32 value)
{
    s32 i;
    for (i = 0; i < 128; i++, p++) {
        if (!*p) {
            *p = value;
            return 1;
        }
    }
    return 0;
}
