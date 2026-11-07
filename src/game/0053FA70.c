#include "common.h"

typedef struct {
    u8 pad0[0x30C];
    s32 f30C;
} Type1;

// 1 unless ARG0->f30C differs from 10 and equals ARG1.
s64 func_0053FA70(Type1 *arg0, s32 arg1) {
    s32 v;
    s64 r = 0;

    if (arg0->f30C != 10) {
        v = (arg0->f30C ^ arg1) == 0;
        r = v;
    }
    return r;
}
