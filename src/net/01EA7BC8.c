/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA8928();
extern void func_01EA89E0(s32 a, s32 b, s32 n);
extern s32 D_00167F34[];

/* Calls the net object's callback at offset 0x28 for a ready handle, clearing *arg5 first and reporting on success. */
s32 func_01EA7BC8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    s32 r;

    if (arg5 == 0) {
        return 2;
    }
    *arg5 = 0;
    if (arg3 == 0) {
        return 2;
    }
    if (func_01EA8928() == 0) {
        return 2;
    }
    if (*(s32 *)((u8 *)arg0 + 0xC) != 1) {
        return 0xC355;
    }
    r = ((s32 (*)(s32, s32, s32, s32, s32, s32 *))((s32 *)D_00167F34[0])[0x28 / 4])(*(s32 *)((u8 *)arg0 + 8), arg1, arg2, arg3, arg4, arg5);
    if (r != 0) {
        return r;
    }
    func_01EA89E0(0, *arg5, 0x1C);
    return 0;
}
