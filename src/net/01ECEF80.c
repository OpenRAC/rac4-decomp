/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x1C]; s32 f1C; } Peer;
typedef struct { char _p0[0x400]; Peer *f400; } Sess;
typedef struct { char _p0[0x138]; Sess *f138; } Ctx;
extern Ctx *D_00167F38;
extern s32 func_01EC9B08(s32 *, Sess *);
extern void func_01EA0368(Sess *, s32);
s32 func_01ECEF80(Sess *s, s32 a, u32 b, s32 *msg) {
    s32 v = 0x100;
    Peer *p;
    if (s == 0) {
        return 4;
    }
    if (b >= 256) {
        return 4;
    }
    if (s != D_00167F38->f138) {
        return 4;
    }
    p = s->f400;
    if (p == 0) {
        return 4;
    }
    if (func_01EC9B08(&v, s) != 0) {
        return 4;
    }
    if (v != 0x100) {
        p->f1C = *msg;
        func_01EA0368(s, -1);
    }
    return 4;
}
