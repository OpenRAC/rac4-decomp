/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct {
    char _p0[0x28];
    void (*f28)(Type1 *, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, char *, s32, s32, s32, s32);
} Type2;
struct Type1 { Type2 *vt; };
typedef struct {
    s32 f0;
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
    Type1 **f80;
    char _p84[0x1C];
    s32 fA0;
    char _pA4[0x10];
    s32 fB4;
    s32 fB8;
    char fBC[0xC8];
    s32 f184;
    s32 f188;
} Type3;
extern void func_01F0C090(void *, s32);
extern s32 func_0011AB04(char *);
extern char D_0019D938[];
void func_01EFE2A4(Type3 *arg0) {
    Type1 *o;
    s32 x;
    o = *arg0->f80;
    if (o == NULL) {
        func_01F0C090(D_0019D938, 0x9C);
    }
    if (arg0->f0 == 0) {
        func_01F0C090(D_0019D938, 0x9D);
    }
    x = arg0->f8 ? arg0->f188 : arg0->f184;
    o->vt->f28(o, arg0->f4, x, arg0->f18, arg0->f1C, arg0->f20, arg0->f24, arg0->f28, arg0->f2C, arg0->f30,
               arg0->f8, arg0->fB8, arg0->fBC, func_0011AB04(arg0->fBC), arg0->fB4, 0, arg0->fA0);
}
