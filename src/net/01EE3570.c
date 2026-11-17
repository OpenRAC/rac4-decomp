/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct { char _p0[0x1C]; s32 f1C; s32 f20; void *f24; char _p28[8]; } Obj;
extern Obj *func_01EE3DB0(s32, s32);
extern void *func_0011A518(void *, s32, u32);
extern void *func_01EE3E14(s32, s32, s32);
Obj *func_01EE3570(s32 a, s32 pool) {
    Obj *o = func_01EE3DB0(pool, sizeof(Obj));
    void *r;
    if (o == 0) {
        return 0;
    }
    func_0011A518(o, 0, sizeof(Obj));
    o->f1C = 1;
    o->f20 = pool;
    if (a != 0) {
        r = func_01EE3E14(pool, a, 0);
        o->f24 = r;
        if (r == 0) {
            return 0;
        }
    }
    return o;
}
