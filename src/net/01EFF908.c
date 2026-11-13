/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(void *, s32);
extern void *func_01EF370C(s32);
extern void func_01EFE878(void *, s32, s32);
extern char D_0019DA60[];
void func_01EFF908(s32 arg0, s32 arg1, void **arg2, s32 arg3, s32 arg4) {
    void *obj;
    if (arg1 == 0 || arg3 == 0 || arg4 == 0) {
        func_01F0C090(D_0019DA60, 0x1E);
    }
    obj = func_01EF370C(0x69EC);
    func_01EFE878(obj, arg1, arg4);
    *arg2 = obj;
}
