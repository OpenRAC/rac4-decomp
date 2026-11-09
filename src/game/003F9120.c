/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_00127A08(s32);
extern s32 func_0012A718();

/* retries func_0012A718 up to 100 times, waiting between failures */
s32 func_003F9120(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, s32 sp0)
{
    s32 i = 0;
    s32 ret;

    while (1) {
        i++;
        if (i > 100) {
            ret = -1;
            break;
        }
        if (func_0012A718(a0, a1, a2, a3, t0, t1, t2, t3, sp0) == 0) {
            ret = 0;
            break;
        }
        if (func_00127A08(10000) < 0) {
            ret = -1;
            break;
        }
    }
    return ret;
}
