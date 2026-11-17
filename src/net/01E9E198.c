/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x460]; s32 f460; } Obj_464;
typedef struct { Obj_464 *obj; s8 f4; char _p5[3]; s32 f8; s32 fC; s32 _p10[9]; s32 f34; s32 f38; s32 f3C; } Req_40;
typedef struct { s32 _p[12]; } Res_30;
extern void *func_0011A518(void *, s32, s32);
extern s32 func_01EA42D8(s32);
extern s32 func_01EA57B8();
extern s32 func_01EA57F8();
extern s32 func_01EA1270(Req_40 *, Res_30 *, s32);
s32 func_01E9E198(s8 kind, Obj_464 *obj, s32 c, s32 d, s32 e, s32 f, s32 g) {
    Req_40 q;
    Res_30 res;
    s32 r;
    s32 t;
    r = func_01EA42D8(func_01EA57B8());
    if (r != 0) {
        return r;
    }
    func_0011A518(&q, 0, sizeof(q));
    q.f4 = kind;
    q.fC = c;
    q.f34 = obj->f460;
    q.f8 = e;
    q.f38 = f;
    q.f3C = g;
    q.obj = obj;
    t = func_01EA1270(&q, &res, d);
    r = func_01EA42D8(func_01EA57F8());
    return r == 0 ? t : r;
}
