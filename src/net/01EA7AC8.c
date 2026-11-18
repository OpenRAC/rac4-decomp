/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00167F34[];
s32 func_01EA8928(void *handle);
s32 func_01EA7EC8(void *, void *);
s32 func_01EA89E0(s32, s32, s32);

// Sends a request to the net object's callback at 0x24, after the connection-state checks.
s32 func_01EA7AC8(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 sp0;
    s32 temp_a0;
    s32 var_v0;

    var_v0 = 2;
    *arg3 = 0;
    if (arg1 == 0) {
        return var_v0;
    }
    var_v0 = func_01EA8928(arg0);
    if (var_v0 == 0) {
        return 2;
    }
    temp_a0 = *(s32 *)((u8 *)arg0 + 0xC);
    if (temp_a0 != 0) {
        var_v0 = 0xC355;
        if (temp_a0 != 2) {
            return var_v0;
        }
    }
    if (*(s32 *)((u8 *)arg0 + 0x20) == 0 && temp_a0 == 0) {
        sp0 = 0;
        var_v0 = func_01EA7EC8(arg0, &sp0);
        if (var_v0 != 0) {
            return var_v0;
        }
        if (sp0 == 0) {
            *arg3 = 0;
            return var_v0;
        }
        *(s32 *)((u8 *)arg0 + 0x20) = 1;
    }
    var_v0 = ((s32 (*)(s32, s32, s32, s32 *))(*(s32 *)((u8 *)D_00167F34[0] + 0x24)))(*(s32 *)((u8 *)arg0 + 0x8), arg1, arg2, arg3);
    if (var_v0 != 0) {
        return var_v0;
    }
    func_01EA89E0(0, *arg3, 0x28);
    return 0;
}
