/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; } Type1;
extern s32 func_0051ED70(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern s32 func_L00_0051EBD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* Lazily initialises the item, then looks up a value through func_0051ED70. */
s32 func_L00_00519320(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, Type1 *arg5) {
    s32 result;
    s32 ret;

    if (!(arg5->f14 & 0x100)) {
        arg5->f14 |= 0x100;
        func_L00_0051EBD0(arg5->fC, arg5->f8, arg5->f4, 0, 0);
    }
    ret = func_0051ED70(arg5->fC, arg0, &result, arg2, arg3, arg4, 0);
    if (arg1 != 0) {
        *arg1 = result;
    }
    return ret != 0 ? 0 : result;
}
