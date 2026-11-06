/* cflags: -Wa,-G0 */
#include "common.h"

extern f32 func_00136378(f32);

// Converts the integer argument and passes the scaled value to the callee.
f32 func_0014C368(s32 arg0) {
    return func_00136378(5.075174f - ((f32)arg0 * 0.01174797f));
}
