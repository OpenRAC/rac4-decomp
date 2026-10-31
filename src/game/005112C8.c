#include "common.h"

extern void *func_00488C98(s32);

/* Calls func_00488C98 with arg0, then calls the function at +4 of its result with arg0; returns 0 for a null arg0. */
s32 func_005112C8(s32 arg0) {
    s32 (*fn)(s32);

    if (arg0 == 0) {
        return 0;
    }
    fn = *(s32 (**)(s32))((u8 *)func_00488C98(arg0) + 4);
    return fn(arg0);
}
