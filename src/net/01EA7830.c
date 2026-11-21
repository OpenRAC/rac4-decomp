/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA8928(void *handle);
extern void func_01EA89E0(s32 a, s32 b, s32 n);
extern s32 D_00167F34[];

typedef struct {
    s32 f0;
    s32 f4;
} Type2;

/* Checks the handle, forwards the request through the net vtable at 0x14 and reports the result. */
s32 func_01EA7830(u8 *arg0, Type2 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    s32 ret;

    if (((s32 (*)(Type2))(*(s32 *)((u8 *)D_00167F34[0] + 0x54)))(arg1) != 0) {
        return 2;
    }
    *arg5 = 0;
    if (arg3 == 0) {
        return 2;
    }
    if (func_01EA8928((void *)arg0) == 0) {
        return 2;
    }
    if (*(s32 *)(arg0 + 0xC) != 1) {
        return 0xC355;
    }
    ret = ((s32 (*)(s32, Type2, s32, s32, s32, s32 *))(*(s32 *)((u8 *)D_00167F34[0] + 0x14)))(*(s32 *)(arg0 + 8), arg1, arg2, arg3, arg4, arg5);
    if (ret != 0) {
        return ret;
    }
    func_01EA89E0(*arg5, 0, 0x1C);
    return 0;
}
