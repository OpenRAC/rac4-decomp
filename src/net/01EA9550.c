/* cflags: @ee296 -O2 -G0 */
#include "common.h"

void func_0011A518(void *, s32, s32);
s32 func_01EA94D0(s32 *);

s32 func_01EA9550(s32 *arg0, s64 arg1) {
    s32 var_v0;

    var_v0 = 0x64;
    if (arg0 != NULL) {
        *arg0 = 0;
        var_v0 = func_01EA94D0(arg0);
        if (var_v0 == 0) {
            if (*arg0 != 0) {
                func_0011A518((void *)*arg0, 0, arg1);
                return 0;
            }
            return 0x64;
        }
    }
    return var_v0;
}
