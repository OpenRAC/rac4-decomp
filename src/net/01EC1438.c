/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0011A2DC(void *, void *, s32);
s32 func_01EC1438(s32 arg0, void *arg1, s32 *arg2) {
    s32 ret = 0;
    u16 buf;
    if (arg2 == NULL) {
        return 0xD2F3;
    }
    buf = 0;
    if (func_0011A2DC(&buf, arg1, 2) != 0 || *arg2 != 0xD) {
        ret = 0xD2F4;
        if (*arg2 != 0xD) {
            ret = 0xD2F5;
        }
    }
    return ret;
}
