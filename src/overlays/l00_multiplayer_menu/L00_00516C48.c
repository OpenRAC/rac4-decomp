/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);

// Forwards arg1..arg3 to the handler at arg0->f0->f18, with the optional notifier at arg0->f4 called before and after, or reports -2 when the child is missing.
s32 func_L00_00516C48(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 (*temp_s1)(void *, s32, s32, s32, s32, s32);
    s32 var_v0;
    void *temp_v1;

    if (arg0 == 0) {
        var_v0 = 0;
    } else {
        if (*(void **)((u8 *)arg0 + 0x0) == 0 || *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x0) + 0x18) == 0) {
            func_L00_004F84C8(0x20, 0x65, 0x6F, 0, 0);
            var_v0 = -2;
        } else {
            temp_s1 = *(s32 (**)(void *, s32, s32, s32, s32, s32))((u8 *)arg0 + 0x4);
            if (temp_s1 != 0) {
                var_v0 = temp_s1(arg0, 6, arg3, arg1, arg2, 1);
                if (var_v0 <= 0) {
                    goto end;
                }
            }
            temp_v1 = *(void **)((u8 *)arg0 + 0x0);
            var_v0 = (*(s32 (**)(void *, s32, s32, s32))((u8 *)temp_v1 + 0x18))(arg0, arg1, arg2, arg3);
            if (temp_s1 != 0) {
                var_v0 = temp_s1(arg0, 0x86, arg3, arg1, arg2, var_v0);
            }
        }
    }
end:
    return var_v0;
}
