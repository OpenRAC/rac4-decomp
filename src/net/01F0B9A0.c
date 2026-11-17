/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(void *, s32);
extern void *func_01EF370C(s32);
extern void func_01F0AAC8(void *, s32, s32);
extern char D_0019E6D0[];
void func_01F0B9A0(s32 arg0, s32 arg1, void **arg2, s32 arg3, s32 arg4) {
    void *obj;
    if (arg3 == 0 || arg1 == 0) {
        func_01F0C090(D_0019E6D0, 0x1A);
    }
    obj = func_01EF370C(0xE4);
    func_01F0AAC8(obj, arg1, arg4);
    *arg2 = obj;
}
