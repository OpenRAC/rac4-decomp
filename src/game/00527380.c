#include "common.h"

typedef struct {
    u8 pad0[0x2F14];
    s32 f2F14;
} Type1;

// 1 unless ARG0->f2F14 differs from 10 and equals ARG1.
s64 func_00527380(Type1 *arg0, s32 arg1) {
    s32 v;
    s64 r = 0;

    if (arg0->f2F14 != 10) {
        v = (arg0->f2F14 ^ arg1) == 0;
        r = v;
    }
    return r;
}
