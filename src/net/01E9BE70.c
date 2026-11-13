/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; } Type1;
extern s32 func_01E9B838(s32, Type1 *, s32, s32, s32 *);
extern s32 func_01E9B788(s32, s32, Type1 *, s32 *, s32 *);
extern s32 func_01E9B890(s32, s32, Type1 *, s32, s32 *);
s32 func_01E9BE70(s32 arg0, Type1 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    s32 r;
    arg1->f0 = arg2;
    arg1->f4 = arg3;
    arg1->f8 = (s32)arg5;
    r = func_01E9B838(arg0, arg1, 3, arg4, arg5);
    if (r < 0) {
        return r;
    }
    if (func_01E9B788(arg0, 0x9, arg1, arg5 + 3, arg5 + 3) < 0) {
        return -0x21E;
    }
    r = func_01E9B890(arg0, arg4, arg1, 3, arg5);
    if (r >= 0) {
        r = arg1->f0;
    }
    return r;
}
