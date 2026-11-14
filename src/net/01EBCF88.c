/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x1E4]; s32 f1E4; } Obj;
s32 func_01EC2268(u32 *, s32);
s32 func_01EC2280(s32, u32);
s32 func_01EBCF88(Obj *o, s32 a1) {
    u32 n;
    if (o->f1E4 != 0) {
        func_01EC2268(&n, a1);
        n >>= 2;
        func_01EC2280(a1, n);
    }
    return 0;
}
