/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x8]; s32 f8; char _pC[4]; void *f14; } Ring;
typedef struct { u8 f0; char _p1[3]; u8 f4; char _p5[7]; s32 fC; void *f10; char _p14[0x18]; Ring q; } Ent;
typedef struct { char _p0[0x10C]; u32 f10C; } Ctx;
typedef struct { char _p0[0x404]; s32 f404; } Sess;
extern Ctx *D_00167F38;
extern Sess *D_001B7390;
extern s32 func_01ECC410(s32 *, u32);
extern Ent *func_01EC9A28(u32);
extern s32 func_01EA6EC0(Ring *, void *, s32);
extern void func_01EA70B0(Ring *, s32);
extern void *func_0011A370(void *, const void *, u32);
s32 func_01ECB988(u32 id, void *buf, s32 len) {
    s32 avail = 0;
    s32 r;
    Ent *e;
    Sess *s;
    if (id >= D_00167F38->f10C) {
        return 0x17;
    }
    if (buf == 0) {
        return 0x17;
    }
    if (len <= 0) {
        return 0x17;
    }
    r = func_01ECC410(&avail, id);
    if (r != 0) {
        return r;
    }
    if (avail < len) {
        return 0x1F;
    }
    e = func_01EC9A28(id);
    if (e == 0) {
        return 0x17;
    }
    s = D_001B7390;
    if (s == 0) {
        return 8;
    }
    if (s->f404 != e->fC) {
        return 9;
    }
    if (func_01EA6EC0(&e->q, buf, len) != 0) {
        return 0x1F;
    }
    func_01EA70B0(&e->q, 1);
    func_0011A370(e->f10, e->q.f14, e->q.f8);
    return 0;
}
