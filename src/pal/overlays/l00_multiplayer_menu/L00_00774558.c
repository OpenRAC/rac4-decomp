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
    s32 x28;
    u8 pad2C[0x4];
} Req;

extern u16 D_002218C8[];
extern u8 D_0015D0E8[];

char *func_0011A9EC(char *, char *);
s32 func_0012E370(void);
long func_0012FEB0(s32, long);
s32 func_01ED6F48(void *, void *, s32);
void func_0015B558(s32);
s32 func_0015B568(void);
void func_0015A080(void);
s32 func_L00_00779A28(Ctx *c, s32 a);

// menu request
u8 *func_L00_00774558(u8 *arg0, s32 arg1) {
    Req r;
    Ctx *c;
    u8 *g;
    s32 ok;
    s32 v;

    c = D_002234A4;
    arg0[3] = 0;
    r.x0 = D_002218C8[0];
    func_0011A9EC(r.x15, c->x64);
    r.x28 = arg1;
    arg0[0x10] = 1;
    c->x0 = 1;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED6F48(&r, D_0015D0E8, 0));
    g = (u8 *)&D_001721E0;
    ok = 1;
    while (arg0[0x10] != 0) {
        if (func_0015B568() != 0 || *(s32 *)(g + 0x2C4) != 0) {
            c->x10 = 0x38;
            if (c->x14 == 0) {
                c->x14 = 0x38;
            }
            ok = 0;
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
    arg0[0x10] = 0;
    if (ok != 0) {
        v = *(s32 *)(arg0 + 0x29C);
        if (v == -0x3DF || v == -0x3D1) {
            v = 0x3F;
        } else if (v != 0) {
            v = 0x38;
        } else {
            goto skip;
        }
        c->x10 = v;
        if (c->x14 == 0) {
            c->x14 = v;
        }
        ok = 0;
    skip:;
    }
    return ok ? arg0 + 0x284 : NULL;
}
