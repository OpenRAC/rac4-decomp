#include "common.h"

extern void func_0050DE18(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* If the record's code at +4 is 0x6E or 0x44D, call func_0050DE18 with its field at +8 and return 1; otherwise return 0. */
s32 func_0050DD18(void *arg0, u8 *arg1) {
    s32 var_s0 = 1;
    u16 code = *(u16 *)(arg1 + 4);
    if (code == 0x6E) {
        s32 v = *(s32 *)(arg1 + 8);
        func_0050DE18(arg0, v, v, v, v);
    } else if (code == 0x44D) {
        s32 v = *(s32 *)(arg1 + 8);
        func_0050DE18(arg0, v, v, v, v);
    } else {
        var_s0 = 0;
    }
    return var_s0;
}
