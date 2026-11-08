#include "common.h"

typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub;
typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub sub;
} Obj;
extern void func_004EDD90(void *, void *, s32);
extern s32 func_00453C68(s32, s32, f32);
extern void func_00490AC8(Obj *);
extern s32 func_00453508(s16 *);

/* from rac3-decomp's func_L01_0046B3A8 */
void func_L00_00611500(Obj *o) {
    Sub *s;
    f32 t;
    if (func_00453508(&o->timer) != 0) {
        func_00490AC8(o);
        return;
    }
    s = &o->sub;
    func_004EDD90(o->vec, o->vec, 0);
    t = o->timer * s->scale;
    o->result = func_00453C68(s->a, s->b, t);
    o->out = ((o->sub.target - s->base) * t + s->base) * 210000.0f;
}
