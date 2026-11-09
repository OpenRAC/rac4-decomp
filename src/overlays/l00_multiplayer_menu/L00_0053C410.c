/* cflags: @ee29 -O2 -G8 */
#include "common.h"

s32 *func_0011A1A0(void);
s32 func_0012BBF0(s32, s32, s32);
void func_004F7210(void *);
s32 func_005419D8(s32);
void func_L00_004F7228(void *);
s32 func_L00_0053C410(void *arg0, s32 arg1, s32 arg2) {
    s32 value;
    *func_0011A1A0() = 0;
    value = func_0012BBF0(*(s32 *)((u8 *)arg0 + 0x1C), arg1, arg2);
    func_L00_004F7228(arg0);
    if (value <= 0 && func_005419D8(value) != 0) {
        func_004F7210(arg0);
    }
    return value;
}
