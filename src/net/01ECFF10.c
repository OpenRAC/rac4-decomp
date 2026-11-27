/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; u32 f10; char _p14[0x78]; u16 *f8C; } Chan;
typedef struct { char _p0[0x474]; s32 f474; } Sess;
typedef struct { char _p0[0x74]; s32 (*f74)(s32, u8, u16, s32 *); } Api;
typedef struct { Sess *f0; u32 f4; u32 f8; s32 fC; } Res;
extern Api *D_00167F3C;
extern Chan *func_01ED2458(Sess *, u32);
extern s32 func_01EA42D8(s32);

s32 func_01ECFF10(Sess *s, u32 v, Res *r) {
    s32 sp0 = 0;
    Chan *c;
    u16 w;
    u32 i;
    if (r == 0) {
        return 0x17;
    }
    r->f0 = s;
    r->f4 = v;
    r->f8 = 0;
    r->fC = 0;
    if (v >= 0x100) {
        return 0x17;
    }
    c = func_01ED2458(s, v);
    if (c == 0) {
        return 0x17;
    }
    w = c->f8C[v];
    for (i = 0; i < c->f10; i++) {
        if (func_01EA42D8(D_00167F3C->f74(s->f474, i, w, &sp0)) == 0 && sp0 != 0) {
            r->f8 = 1;
            r->fC = i;
            break;
        }
    }
    return 0;
}
