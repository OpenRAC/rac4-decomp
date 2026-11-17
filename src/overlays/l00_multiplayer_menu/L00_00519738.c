/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_00517808(void);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);

// Calls the handler stored at ctx+0x30 with the six arguments, or reports -1 when none is set.
s32 func_L00_00519738(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *ctx = func_00517808();
    s32 (*callback)(s32, s32, s32, s32, s32, s32) = *(s32 (**)(s32, s32, s32, s32, s32, s32))((u8 *)ctx + 0x30);
    s32 ret;
    if (callback == 0) {
        func_L00_004F84C8(0xA, 0x69, 0xE, 0, 0);
        ret = -1;
    } else {
        ret = callback(arg0, arg1, arg2, arg3, arg4, arg5);
    }
    return ret;
}
