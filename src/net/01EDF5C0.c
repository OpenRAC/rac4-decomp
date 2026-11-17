/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef void *(*AllocFn)(s32);
typedef struct { s32 f0; char _p4[0x2C]; s32 f30; char _p34[0xC]; AllocFn f40; s32 f44; s32 f48; char _p4C[0x3C8]; s32 f414; s32 f418; void *f41C; void *f420; char _p424[0x800]; } Obj;
extern s32 D_0016A930;
extern AllocFn D_0016A934;
extern s32 D_0016A938;
extern s32 D_0016A93C;
extern s32 D_0016A940;
extern s32 D_0016A944;
extern char D_00199F28[];
extern char D_00199FA8[];
extern void func_0011EAA0(void *, s32, void *);
extern void *func_0011A518(void *, s32, u32);
s32 func_01EDF5C0(Obj **out) {
    Obj *o;
    if (D_0016A934 == 0) {
        func_0011EAA0(D_00199F28, 0xFA, D_00199FA8);
    }
    o = D_0016A934(sizeof(Obj));
    *out = o;
    if (o == 0) {
        return -4;
    }
    func_0011A518(o, 0, sizeof(Obj));
    o->f40 = D_0016A934;
    o->f44 = D_0016A938;
    o->f48 = D_0016A93C;
    o->f0 = 1;
    o->f414 = D_0016A940;
    o->f418 = D_0016A944;
    D_0016A930++;
    o->f41C = D_0016A934(D_0016A940);
    o->f420 = D_0016A934(D_0016A944);
    o->f30 = 0;
    return 0;
}
