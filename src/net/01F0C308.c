/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(void *, s32);
extern void *func_01EF370C(s32);
extern void func_01F0C1F8(void *, s32, s32);
extern char D_0019E8E8[];
void func_01F0C308(s32 arg0, s32 arg1, void **arg2, s32 arg3, s32 arg4) {
    void *obj;
    if (arg1 == 0 || arg3 == 0 || arg4 == 0) {
        func_01F0C090(D_0019E8E8, 0x1B);
    }
    obj = func_01EF370C(0xB4);
    func_01F0C1F8(obj, arg1, arg4);
    *arg2 = obj;
}
