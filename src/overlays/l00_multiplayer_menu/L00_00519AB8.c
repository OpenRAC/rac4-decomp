/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern void func_L00_00528C38(void *, s32);
void func_L00_00519AB8(void *arg0, void *arg1, void *arg2) {
    s32 ctx = *(s32 *)((u8 *)arg0 + 0x78);
    if (arg2 != 0) __builtin_memcpy((u8 *)arg0 + 0x0C, arg2, 8);
    __builtin_memcpy((u8 *)arg0 + 0x2C, (u8 *)arg0 + 0x0C, 8);
    if (arg1 != 0) {
        func_L00_00528C38(arg1, ctx);
        func_L00_00528C38((u8 *)arg1 + 8, ctx + 0x180);
        func_L00_00528C38((u8 *)arg1 + 0x10, ctx + 0x300);
    }
}
