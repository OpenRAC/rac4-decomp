#include "common.h"
#include "pal/global_002234A4.h"
#include "pal/profile_001721E0.h"

typedef struct Ctx {
    u8 x0;
    u8 pad1[7];
    s32 x8;
    u8 padC[4];
    s32 x10;
    s32 x14;
    u8 pad18[4];
    u8 x1C;
    u8 pad1D[0x47];
    char *x64;
} Ctx;

typedef struct Req {
    u16 x0;
    u8 pad2[0x13];
    char x15[0x13];
} Req;

extern u16 D_002219D0[];
extern u8 D_0015D480[];

char *func_0011A9EC(void *, void *);
s32 func_00161280(void);
s32 func_00161320(s32);
s32 func_0012E370(void);
long func_0012FEB0(s32, long);
s32 func_01ED6380(void *, void *, s32);
void func_0015B558(s32);
s32 func_0015B568(void);
void func_0015A080(void);
s32 func_L00_00779A28(Ctx *c, s32 a);
s32 func_L00_0077F558(u8 *p);
void func_L00_00778EF0(Ctx *c);

// Network request with func_01ED6380 unless func_00161280/func_00161320 refuse it (error 7); flag at +0x154. Fails on a negative +0x170, then runs func_L00_0077F558 when +0x11E is set and func_L00_00778EF0 when arg1 is set.
s32 func_L00_0077E978(u8 *arg0, s32 arg1) {
    Req r;
    Ctx *c;
    u8 *g;
    s32 ok;

    c = D_002234A4;
    if (func_00161280() != 0 && func_00161320(1) != 0) {
        c->x10 = 7;
        if (c->x14 == 0) {
            c->x14 = 7;
        }
        return 0;
    }
    r.x0 = D_002219D0[0];
    func_0011A9EC(r.x15, c->x64);
    arg0[0x154] = 1;
    c->x0 = 1;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED6380(&r, D_0015D480, 0));
    g = (u8 *)&D_001721E0;
    ok = 1;
    while (arg0[0x154] != 0) {
        if (func_0015B568() != 0 || *(s32 *)(g + 0x2C4) != 0) {
            c->x10 = 0x56;
            if (c->x14 == 0) {
                c->x14 = 0x56;
            }
            ok = 0;
            break;
        }
        c->x1C = 1;
        func_0015A080();
        c->x1C = 0;
        if (func_L00_00779A28(c, 1) == 0) {
            ok = 0;
            break;
        }
    }
    c->x0 = 0;
    arg0[0x154] = 0;
    if (ok != 0 && *(s32 *)(arg0 + 0x170) < 0) {
        c->x10 = 0x56;
        if (c->x14 == 0) {
            c->x14 = 0x56;
        }
        ok = 0;
    }
    if (arg0[0x11E] != 0 && func_L00_0077F558(arg0) == 0) {
        ok = 0;
    }
    if (arg1 != 0) {
        func_L00_00778EF0(c);
    }
    return ok;
}
