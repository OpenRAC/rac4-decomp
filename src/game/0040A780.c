/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_00413928(s32 a0, s32 a1, s32 a2, s32 *a3);
s32 func_0040A810(s32 *, s32, s32, s32, s32);
s32 func_0040A780(s32 *h, s32 a, s32 b, s32 c, s32 d) {
    s32 v;
    if (d == 0) {
        v = c;
    } else if (func_00413928(*h, d, c, &v) != 0) {
        return 0x803;
    }
    return func_0040A810(h, a, b, v, d);
}
