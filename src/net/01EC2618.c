/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; char _p8[0xC]; s32 f14; } Obj;
extern s32 func_01EA9550(Obj **, s32);
extern s32 func_01EA7D48(s32 *);
extern void func_01EA95C0(Obj **);
s32 func_01EC2618(Obj **out, s32 a, s32 b) {
    Obj *o = 0;
    s32 r;
    if (out == 0) {
        return 2;
    }
    *out = 0;
    if (a == 0) {
        return 2;
    }
    if (func_01EA9550(&o, 0x4C) != 0) {
        return 100;
    }
    r = func_01EA7D48(&o->f4);
    if (r != 0) {
        func_01EA95C0(&o);
        return r;
    }
    o->f14 = b;
    o->f0 = a;
    *out = o;
    return r;
}
