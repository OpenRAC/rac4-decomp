/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 {
    u8 pad0[0x4];
    s32 f4;
} Type1;

s32 func_01ED9310(void);
s32 func_01ED9820(Type1 *, s32, s32);

s32 func_01ED9960(Type1 *arg0, s32 arg1)
{
    s32 r;

    if (func_01ED9310() == 0) {
        return -0x15;
    }
    r = func_01ED9820(arg0, 2, arg1);
    if (r == 0) {
        arg0->f4 = 2;
    }
    return r;
}
