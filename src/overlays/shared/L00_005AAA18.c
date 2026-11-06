/* cflags: -mno-split-addresses */
#include "common.h"

f32 func_L00_005BCE18(f32);

f32 func_L00_005AAA18(f32 fparg0) {
    f32 var_f0;

    var_f0 = func_L00_005BCE18(fparg0 * 1.5707964f);
    if (var_f0 < 0.1f) {
        var_f0 = 0.0f;
    }
    return var_f0;
}
