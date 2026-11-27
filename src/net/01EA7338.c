/* cflags: @ee296 -O2 -G0 -fno-schedule-insns */
#include "common.h"

typedef struct { s32 f0, f4, f8, fC, f10; } Obj;

extern s32 func_01EA7248(void *object, s32 *out);

s32 func_01EA7338(Obj *arg0, s32 *arg1) {
    s32 value = 0;
    s32 r;

    if (arg0 == 0) {
        return 2;
    }
    if (arg1 == 0) {
        return 2;
    }
    r = func_01EA7248(arg0, &value);
    if (r != 0) {
        return r;
    }
    if (value != 0) {
        *arg1 = arg0->f10 + arg0->f4;
    } else {
        return 0xC8;
    }
    return 0;
}
