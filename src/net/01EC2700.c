/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; } A8;
typedef struct { u8 b[4]; } Buf4;
typedef struct { A8 addr; s32 f24; s32 f28; s32 f2C[2]; s32 f34; s32 f38; } Sub;
typedef struct { s32 f0; char _p4[0x18]; Sub sub; s32 f3C; void *f40; } Obj;
extern void *func_0011A518(void *, s32, u32);
extern s32 func_01EA7830(s32, A8, s32, Buf4 *, s32, s32 *);
extern s32 func_01EAB288(s32 *);
s32 func_01EC2700(Obj *o, A8 addr, s32 a, void *b) {
    Buf4 buf;
    s32 cnt = 0;
    s32 r;
    if (o == 0) {
        return 2;
    }
    if (o->f3C != 0) {
        return 0xD6DA;
    }
    if (addr.f0 == 0) {
        return 2;
    }
    if (b == 0) {
        return 2;
    }
    func_0011A518(&o->sub, 0, sizeof(Sub));
    o->sub.f28 = 0;
    o->sub.addr = addr;
    o->sub.f24 = a;
    o->f40 = b;
    buf.b[2] = 0xE4;
    r = func_01EA7830(o->f0, o->sub.addr, a, &buf, 4, &cnt);
    if (r != 0) {
        return r;
    }
    if (cnt != 4) {
        return r;
    }
    func_01EAB288(o->sub.f2C);
    o->sub.f34++;
    o->f3C = 1;
    return 0;
}
