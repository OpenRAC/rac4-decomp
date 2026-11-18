/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Obj Obj;
s32 func_003FD5F8(Obj *);
s32 func_003FF868(Obj *);
s32 func_004077A0(Obj *, Obj *, s32, s32);
s32 func_003FF4F8(Obj *a, Obj *b, s32 c, s32 d) {
    s32 r = func_003FD5F8(a);
    if (r != 0) {
        return r;
    }
    r = func_003FF868(b);
    if (r != 0) {
        return r;
    }
    return func_004077A0(a, b, c, d);
}
