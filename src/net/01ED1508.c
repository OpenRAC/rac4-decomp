/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA42D8(s32);
extern void *func_01ED2458();
extern s32 D_00167F3C[];

/* Look up an object; if found, call the function in the global table with a field of the object and an index, and pass its result on. */
s32 func_01ED1508(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_v0;
    s32 idx;

    idx = arg1;
    temp_v0 = (s32)func_01ED2458();
    var_v0 = 0x17;
    idx = idx << 1;
    if (temp_v0 != 0) {
        var_v0 = func_01EA42D8(((s32 (*)(s32, s32))*(s32 *)(D_00167F3C[0] + 0x2C))(*(s32 *)(arg0 + 0x474), *(s32 *)(temp_v0 + 0x8C) + idx));
    }
    return var_v0;
}
