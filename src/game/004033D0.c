/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_004033B0(s32);
s32 func_003FBA08(s32, s32);
void func_003FB868(s32);
s32 func_004033D0(s32 a, s32 b) {
    s32 r;
    if (a == 0) {
        return func_004033B0(b);
    }
    r = func_003FBA08(a, b ? b : 1);
    if (r == 0) {
        func_003FB868(a);
    }
    return r;
}
