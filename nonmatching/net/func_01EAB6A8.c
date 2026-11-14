/* Not matching yet: BYTES 29/88 (tools/try_func.py func_01EAB6A8 --diff). Not part of the build. */
/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 func_01EABAF8(void);
extern s32 D_1B23E8[];

s32 func_01EAB6A8(s32 *arg0) {
    s32 var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        var_v0 = func_01EABAF8();
        if (var_v0 != 0) {
            return 0x640;
        }
        arg0[0] = D_1B23E8[0];
        arg0[1] = D_1B23E8[2];
    }
    return var_v0;
}
