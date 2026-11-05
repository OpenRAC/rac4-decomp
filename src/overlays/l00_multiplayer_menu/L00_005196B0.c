/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern void *func_00517808(void);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
s32 func_L00_005196B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *ctx = func_00517808();
    s32 (*callback)(s32, s32, s32, s32) = *(s32 (**)(s32, s32, s32, s32))((u8 *)ctx + 0x2C);
    if (callback == 0) {
        func_L00_004F84C8(0xA, 0x6A, 0xE, 0, 0);
        return -1;
    }
    return callback(arg0, arg1, arg2, arg3);
}
