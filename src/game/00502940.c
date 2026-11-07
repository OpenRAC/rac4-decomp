#include "common.h"

extern s32 func_005028C0(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);
extern s32 func_00503708(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00504F68(s32, s32);

/* Looks up an entry through func_005028C0, then returns whether both func_00503708 and func_00504F68 succeed for it (1 if the lookup fails). */
s32 func_00502940(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 sp0;
    s32 sp4;
    s32 ret;
    s32 p;

    sp0 = 0;
    sp4 = 0;
    ret = 1;
    p = func_005028C0(arg0, arg2, &sp0, &sp4);
    if (p != 0) {
        s32 a = func_00503708(p, 1, 1, arg5, arg1, sp0, 0) != 0;
        s32 b = func_00504F68(arg5, 1) != 0;
        ret = a & b;
    }
    return ret;
}
