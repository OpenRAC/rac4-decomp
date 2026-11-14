/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x468]; s32 f468; } Obj_46c;
typedef struct { s32 w[11]; } Sub_2c;
typedef struct { Obj_46c *obj; u8 f4; char _p5[3]; s32 f8; Sub_2c sub; s32 f38; s32 f3C; } Req_40;
typedef struct { s32 f0; Sub_2c sub; } Res_30;
typedef struct { u8 kind; char _p1[3]; Obj_46c *obj; Res_30 *res; } Cb_c;
extern s32 func_01EAAB18(s32, s32, s32, s32, void (*)(), Cb_c *);
extern void func_01EA11F8();
extern s32 func_01EA42D8(s32);
s32 func_01EA1270(Req_40 *q, Res_30 *res, s32 c) {
    Cb_c cb;
    Obj_46c *o = q->obj;
    s32 r;
    u8 k;
    s32 n;
    if (o == 0) {
        return 0x17;
    }
    if (o->f468 == 4) {
        return 0xF;
    }
    res->sub = q->sub;
    n = q->f38;
    if (n >= 0x1FF) {
        cb.kind = q->f4 | 0x50;
    } else {
        cb.kind = q->f4;
    }
    cb.obj = o;
    cb.res = res;
    r = func_01EAAB18(c, q->f8, q->f3C, n, func_01EA11F8, &cb);
    if (r != 0 && res->f0 == 0) {
        res->f0 = func_01EA42D8(r);
    }
    return res->f0;
}
