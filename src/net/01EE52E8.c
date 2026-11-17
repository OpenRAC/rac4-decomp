/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct { s32 f0; char _p4[0xC]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20; s32 f24; char _p28[8]; } Query;
typedef struct Obj Obj;
typedef struct { char _p0[0x58]; void (*f58)(Obj *, Query *); } VT;
struct Obj { VT *vt; };
extern void *func_0011A518(void *, s32, u32);
s32 func_01EE52E8(Obj *o, s32 a, s32 b, s32 *p20, s32 *p24, s32 *p0) {
    Query q;
    func_0011A518(&q, 0, sizeof(q));
    q.f14 = b;
    q.f10 = a;
    o->vt->f58(o, &q);
    *p24 = q.f24;
    *p20 = q.f20;
    *p0 = q.f0;
    return q.f0 == 10;
}
