/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EAB500(u32 *arg0, u32 *arg1)
{
    u32 a;

    if (arg0 == NULL) {
        return 2;
    }
    if (arg1 == NULL) {
        return 2;
    }
    a = arg0[0];
    if (a > 0x418935) {
        return 0x641;
    }
    *arg1 = a * 0x3E8 + arg0[1] / 1000;
    return 0;
}
