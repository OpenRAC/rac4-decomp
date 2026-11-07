#include "common.h"

typedef struct {
    u8 pad0[0x28];
    s32 f28;
} Type1;

// 1 unless ARG0->f28 differs from 10 and equals ARG1.
s64 func_00540AB0(Type1 *arg0, s32 arg1) {
    s32 v;
    s64 r = 0;

    if (arg0->f28 != 10) {
        v = (arg0->f28 ^ arg1) == 0;
        r = v;
    }
    return r;
}
