/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[4]; void (*f4)(s32); } NetOps;
typedef struct {
    char _p0[0x400];
    s32 f400;
    s32 f404;
    s32 f408;
    char _p40C[0x2C];
    s32 f438;
    s32 f43C;
    s32 f440;
    s32 f444;
    s32 f448;
    s32 f44C;
    s32 f450;
    s32 f454;
    s32 f458;
    s32 f45C;
    char _p460[0x14];
    s32 f474;
} Obj_478;
extern NetOps *D_00167F3C;
extern void *func_01EA47E8(Obj_478 *, u32);
extern void *func_0011A518(void *, s32, s32);
extern void func_01EA4770(Obj_478 *);
s32 func_01EA45A0(Obj_478 *o) {
    u32 i = 0;
    void *e;
    if (o->f474 != 0) {
        D_00167F3C->f4(o->f474);
        o->f474 = 0;
    }
    for (; i < 256; i++) {
        e = func_01EA47E8(o, i);
        if (e != 0) {
            func_0011A518(e, 0, 0x2C);
        }
    }
    o->f404 = 256;
    o->f408 = 256;
    o->f458 = -1;
    o->f454 = 0;
    o->f400 = 0;
    o->f438 = 0;
    o->f43C = 0;
    o->f440 = 0;
    o->f444 = 0;
    o->f448 = 0;
    o->f44C = 0;
    o->f450 = 0;
    o->f45C = 0;
    func_01EA4770(o);
    return 0;
}
