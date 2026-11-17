/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

extern void func_01EA8FD8(s32, void *);
extern s32 func_01EC5618(s32, s32, s32, void *, s32, s32);
s32 func_01EC52E0(s32 arg0) {
    u8 buf[0x40];
    func_01EA8FD8(0, buf);
    return func_01EC5618(arg0, 0x12, 0xFFFF, buf, 0x40, 0xC0);
}
