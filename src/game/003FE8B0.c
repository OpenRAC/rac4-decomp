/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_004033B0(s32 value);
s32 func_003FE980(s32, s32 *, s32);
s32 func_003FE8B0(s32 a0, s32 *a1, s32 a2) {
    s32 p = func_004033B0(a2);
    *a1 = p;
    if (p == 0) {
        return 0x206;
    }
    return func_003FE980(a0, a1, a2);
}
