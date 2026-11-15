/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EAB1B8(s8 *arg0, s32 arg1)
{
    s32 len;
    s8 *end;
    s8 *p;

    len = 0;
    end = arg0 + arg1;
    if (arg0 == 0)
        return len;
    p = arg0;
    if (arg0 < end && *arg0 != 0) {
        do {
            p++;
        } while (p < end && *p != 0);
    }
    return p - arg0;
}
