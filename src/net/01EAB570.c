/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EAB570(u32 *t, s32 *out) {
    if (t == 0) {
        return 2;
    }
    if (out == 0) {
        return 2;
    }
    if (t[0] >= 0x10C5) {
        return 0x641;
    }
    *out = t[0] * 1000000 + t[1];
    return 0;
}
