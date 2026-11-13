/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(void *, s32);
extern void *func_01EF370C(s32);
extern void func_01EFD6F0(void *, s32, s32, s32);
extern char D_0019D8B8[];
void func_01EFDD84(s32 arg0, s32 arg1, void **arg2, s32 arg3, s32 arg4) {
    void *obj;
    if (arg1 == 0 || arg3 == 0) {
        func_01F0C090(D_0019D8B8, 0x1F);
    }
    obj = func_01EF370C(0x198);
    func_01EFD6F0(obj, arg1, arg3, arg4);
    *arg2 = obj;
}
