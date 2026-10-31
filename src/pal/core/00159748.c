/* C adapted from rac3-decomp func_0013D080 (commit cd0e7c20fd8a). */
#include "common.h"

extern s32 func_00158A40(s32, s32, void *);

s32 func_00159748(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f)
{
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_00158A40(0x3B, 0x18, buf);
}
