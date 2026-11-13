/* cflags: @ee296 -O2 -G0 -fno-expensive-optimizations -mno-split-addresses */
#include "common.h"

extern u8 D_0019B460[];

extern void func_01EE7260(s32, s32, s32, s32, void *);
extern void func_01F07F20(void **a0);
extern void func_01F07F50(void **arg0, s32 arg1);
extern void func_01F0C090(const char *, s32);

void func_01EE7010(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 buf[0x10];

    if (arg3 == 0) {
        func_01F0C090(D_0019B460, 0x3CB);
    }
    func_01F07F20((void **)buf);
    func_01EE7260(arg3, arg0, arg1, arg2, buf);
    func_01F07F50((void **)buf, 2);
}
