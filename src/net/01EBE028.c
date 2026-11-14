/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[8]; } A8;
typedef struct { A8 f0; s32 f8; void *fC; s32 f10; } Req;
typedef struct { s32 f0; char _p4[0xC]; s32 f10; char _p14[0x60]; s32 f74; char _p78[0x24]; s32 f9C; char _pA0[0x10]; void *fB0; s32 fB4; } Sess;
typedef struct { char _p0[0x84]; s32 f84; } SessX;
extern s32 func_01EC2618(s32 *, s32, s32);
extern s32 func_01EC2920(s32, s32);
extern s32 func_01EC2868(s32, A8, s32, void *, void *);
extern void func_01EC2228(void);
s32 func_01EBE028(Sess *c, Req *d) {
    s32 r;
    if (c == 0) {
        return 0xD2F2;
    }
    if (d->fC == 0) {
        return 2;
    }
    if (((SessX *)c)->f84 != 0) {
        return 0xD2F4;
    }
    c->fB0 = d->fC;
    c->fB4 = d->f10;
    if (c->f10 == 0) {
        r = func_01EC2618(&c->f10, c->f0, c->f9C);
        if (r != 0) {
            return r;
        }
        r = func_01EC2920(c->f10, c->f74);
        if (r != 0) {
            return r;
        }
    }
    r = func_01EC2868(c->f10, d->f0, d->f8, func_01EC2228, c);
    if (r != 0) {
        return r;
    }
    ((SessX *)c)->f84 = 1;
    return 0;
}
