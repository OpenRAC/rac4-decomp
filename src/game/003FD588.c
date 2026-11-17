/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_003FD5F8(s32);
s32 func_003FE5F0(s32, s32, s32);
s32 func_003FD588(s32 a0, s32 (*cb)(s32 *), s32 a2) {
    s32 t;
    s32 r = func_003FD5F8(a0);
    if (r != 0) {
        return r;
    }
    if (cb(&t) != 0) {
        return 0x213;
    }
    return func_003FE5F0(a0, t, a2);
}
