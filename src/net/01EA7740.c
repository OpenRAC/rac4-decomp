/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA8928(void *handle);
extern s32 func_01EA7EC8(void *arg0, void *arg1);
extern void func_01EA89E0(s32 arg0, s32 arg1, s32 arg2);
extern s32 D_00167F34[];

/* Checks the handle at arg0 and, when it is open, forwards the request through the net vtable. */
s32 func_01EA7740(u8 *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 sp0;
    s32 temp;
    s32 result;

    *arg3 = 0;
    if (func_01EA8928(arg0) == 0) {
        return 2;
    }
    temp = *(s32 *)(arg0 + 0xC);
    if (temp != 0) {
        if (temp != 2) {
            return 0xC355;
        }
    }
    if (*(s32 *)(arg0 + 0x20) == 0 && temp == 0) {
        sp0 = 0;
        result = func_01EA7EC8(arg0, &sp0);
        if (result != 0) {
            return result;
        }
        if (sp0 == 0) {
            *arg3 = 0;
            return 0;
        }
        *(s32 *)(arg0 + 0x20) = 1;
    }
    result = ((s32 (*)())(*(s32 *)((u8 *)D_00167F34[0] + 0x10)))(*(s32 *)(arg0 + 8), arg1, arg2, arg3);
    if (result != 0) {
        return result;
    }
    func_01EA89E0(*arg3, 0, 0x28);
    return 0;
}
