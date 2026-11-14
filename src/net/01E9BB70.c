/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } P_10;
extern s32 func_01E9B788(void *, s32, void *, s32, s32);
extern s32 func_01E9B890(void *, s32, P_10 *, s32, s32);
s32 func_01E9BB70(void *a, P_10 *p, s32 x, s32 y, s32 n, s32 *io, s32 z) {
    s32 r;
    p->f0 = x;
    if (io != 0) {
        p->f4 = *io;
    } else {
        p->f4 = 0;
    }
    p->fC = z;
    p->f8 = n;
    if (func_01E9B788(a, 4, p, 16, n + 8) < 0) {
        return -0x21E;
    }
    if (p->f0 < 0) {
        return p->f0;
    }
    if (io != 0) {
        *io = p->f4;
    }
    r = func_01E9B890(a, y, p, 2, p->f0);
    if (r >= 0) {
        r = p->f0;
    }
    return r;
}
