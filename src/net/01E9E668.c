/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EA0BF0(s32);
s32 func_01E9E668(s32 a0, s32 *out) {
    if (out == 0) {
        return 0x17;
    }
    if (a0 == 0) {
        return 0x17;
    }
    *out = func_01EA0BF0(a0);
    return 0;
}
