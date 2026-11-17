/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x28]; s32 f28; } Obj;
s32 func_01ED9310(Obj *);
s32 func_01ED9B40(s32 a0, Obj *a1) {
    if (func_01ED9310(a1) == 0) {
        return -0x15;
    }
    if (a0 == 0) {
        return -0x15;
    }
    a1->f28 = a0;
    return 0;
}
