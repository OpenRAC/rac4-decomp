/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 func_L00_00537CE8(s32, void *, s32, s32 *);
s32 func_L00_00538DE0(void *, s32, s32, s32 *);
s32 func_L00_005476D8(void *, s32, s32 *);

/* Pushes a 20-byte entry on a counted stack, runs one of two checks on it, then a final call; pops the entry. */
s32 func_L00_0053B900(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4) {
    s32 ret = 0;
    void *entry;

    entry = (char *)arg4 + ((*arg4)++ * 20 + 4);
    if (arg1 == arg2) {
        if (func_L00_005476D8(entry, arg2, arg4) == 0) {
            goto end;
        }
    } else if (func_L00_00538DE0(entry, arg1, arg2, arg4) == 0) {
        goto end;
    }
    ret = func_L00_00537CE8(arg0, entry, arg3, arg4) != 0;
end:
    (*arg4)--;
    return ret;
}
