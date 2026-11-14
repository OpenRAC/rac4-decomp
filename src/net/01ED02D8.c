/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; u32 f10; } Chan;
typedef struct { char _p0[0x474]; s32 f474; } Sess;
typedef struct { s32 f0; Sess *f4; u32 f8; s32 fC; } Req;
typedef struct { char _p0[0x6C]; s32 (*f6C)(s32, u8, u16, s32); } Api;
extern Api *D_00167F3C;
extern Chan *func_01ED2458(Sess *, s32);
extern s32 func_01EA42D8(s32);
s32 func_01ED02D8(Req *q, s32 b) {
    Sess *s;
    Chan *c;
    s32 mode;
    u32 i;
    if (q == 0) {
        return 0x17;
    }
    if (q->f8 >= 256) {
        return 0x17;
    }
    s = q->f4;
    c = func_01ED2458(s, b);
    if (c == 0) {
        return 0x17;
    }
    mode = 3;
    if (q->fC == 0) {
        mode = 0;
    }
    for (i = 0; i < c->f10; i++) {
        s32 r = func_01EA42D8(D_00167F3C->f6C(s->f474, i, q->f8, mode));
        if (r != 0) {
            return r;
        }
    }
    return 0;
}
