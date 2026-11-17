/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct { Type1 *vt; } Type2;
struct Type1 {
    char _p0[0x10];
    s32 (*f10)();
};
s32 func_01EEC50C(Type2 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    return arg0->vt->f10(arg0, arg1, arg4, arg6, arg7, arg8, 0, arg9);
}
