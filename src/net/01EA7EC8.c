/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x48]; s32 (*f48)(s32, s32 *); } Ctx;
typedef struct { char _p0[8]; s32 f8; s32 fC; char _p10[0x10]; s32 f20; } Obj;
extern Ctx *D_00167F34;
s32 func_01EA8928(Obj *);
s32 func_01EA7EC8(Obj *o, s32 *out) {
    s32 r;
    if (func_01EA8928(o) == 0) {
        return 2;
    }
    if (o->fC != 0) {
        return 0xC355;
    }
    if (o->f20 == 0) {
        r = D_00167F34->f48(o->f8, &o->f20);
        if (r != 0) {
            return r;
        }
    }
    *out = o->f20;
    return 0;
}
