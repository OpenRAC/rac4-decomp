/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; u32 f10; char _p14[0x64]; u8 f78; } Chan;
typedef struct { char _p0[0x474]; s32 f474; } Sess;
typedef struct { char _p0[0x60]; s32 (*f60)(s32, u8); } Api;
extern Api *D_00167F3C;
extern Chan *func_01ED2458(Sess *, u32);
extern void func_01ECFD78(Sess *, u8);
extern s32 func_01EA42D8(s32);
s32 func_01ECFCD8(Sess *s, u32 v) {
    Chan *c = func_01ED2458(s, v);
    s32 r;
    if (c == 0) {
        return 0x17;
    }
    if (v >= c->f10) {
        return 0x17;
    }
    if (c->f78 == v) {
        return 0;
    }
    if (c->f78 != 0xFF) {
        func_01ECFD78(s, c->f78);
    }
    r = func_01EA42D8(D_00167F3C->f60(s->f474, v));
    if (r == 0) {
        c->f78 = v;
    }
    return r;
}
