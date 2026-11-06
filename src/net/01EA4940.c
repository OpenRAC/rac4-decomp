/* cflags: @ee296 -O2 -G0 */
#include "common.h"
/* Not matching yet: BYTES 1/48 (tools/try_func.py func_01EA4940 --diff). Not part of the build. */
extern s32 func_01EA8C68();

// Calls func_01EA8C68 with arg0 + 0x410 when arg0 and arg1 are both set; returns 0 then, 0x17 otherwise.
s32 func_01EA4940(s32 arg0, s32 arg1) {
    s32 var_v0 = 0x17;
    if (arg1 != 0 && arg0 != 0) {
        func_01EA8C68(arg0 + 0x410);
        var_v0 = 0;
    }
    return var_v0;
}
