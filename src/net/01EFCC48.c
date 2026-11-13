/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

extern s32 func_01EF370C(s32 arg0);
extern void func_01EFB828(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_01F0C090(const char *arg0, s32 arg1);
extern s32 D_0019D720[];

void func_01EFCC48(s32 unused, s32 arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s32 s0;

    if (arg3 == 0) {
        func_01F0C090((const char *)D_0019D720, 0x1F);
    }
    s0 = func_01EF370C(0x514);
    func_01EFB828(s0, arg1, arg3, arg4, 0);
    *arg2 = s0;
}
