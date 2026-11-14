/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_L00_00526A08(void *);
extern s32 func_0051ECA0(void *, s32, s32 *, u32, s32, s32, s32);

// Looks up the object for arg3 and, when the lookup succeeds, returns the value it reports.
s32 func_L00_005266A0(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4) {
    s32 result;
    s32 out;
    s32 limit;
    void *obj;

    limit = (arg4 == 2) ? 0x800 : 0;
    result = 0;
    obj = func_L00_00526A08(arg3);
    if (obj != 0) {
        if (func_0051ECA0(obj, arg2, &out, 0xFFFFFFFFU, arg1, arg0, limit) == 0) {
            result = out;
        }
    }
    return result;
}
