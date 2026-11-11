/* cflags: @ee296 -O2 -G0 -fno-gcse -Wa,-mips4 */
#include "common.h"

typedef struct Obj Obj;
typedef struct ObjVt {
    char _p0[0x20];
    void (*f20)(Obj *, s32, s32, s32, s32, f32, f32, f32, f32, f32, s32, char *, s32, s32, s32, s32);
} ObjVt;
struct Obj {
    ObjVt *vt;
};

typedef struct Self {
    char _p0[0x4];
    s32 f4;
    s32 f8;
    char _pC[0xC];
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    s32 f2C;
    s32 f30;
    char _p34[0x4C];
    Obj **f80;
    char _p84[0x1C];
    s32 fA0;
    char _pA4[0x10];
    s32 fB4;
    s32 fB8;
    f32 fBC;
    char *fC0;
    char _pC4[0x14];
    s32 fD8;
    s32 fDC;
    s32 fE0;
    s32 fE4;
} Self;

s32 func_0011AB04(char *);
s32 func_01EEC4E8(Obj *, char *, s32, f32);
char *func_01EF7C5C(void);
void func_01F06988(char *);

void func_01EF7830(Self *arg0) {
    Obj *obj;
    s32 len;
    s32 a;
    s32 b;
    s32 c;
    char *s;
    f32 f;

    obj = *arg0->f80;
    s = func_01EF7C5C();
    arg0->fC0 = s;
    func_01F06988(s);
    len = func_0011AB04(arg0->fC0);
    a = arg0->fD8;
    b = arg0->f2C;
    c = arg0->f30;
    if (arg0->f8 != 0) {
        a = arg0->fDC;
        b = arg0->fE0;
        c = arg0->fE4;
    }
    f = arg0->fBC;
    if (f > 0.0f) {
        len = func_01EEC4E8(obj, arg0->fC0, arg0->fB4, f);
    }
    obj->vt->f20(obj, arg0->f4, a, b, c,
                 arg0->f18, arg0->f1C, arg0->f20, arg0->f24, arg0->f28,
                 arg0->f8, arg0->fC0, len, arg0->fB4, arg0->fB8, arg0->fA0);
}
