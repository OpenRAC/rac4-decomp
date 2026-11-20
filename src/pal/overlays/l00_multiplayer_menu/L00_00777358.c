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
} Ctx;

typedef struct Req {
    u16 x0;
    u8 pad2[0x16];
    s32 x18;
    u8 pad1C[0x4];
} Req;

extern u16 D_002218F8[];
extern u8 D_0015D788[];

s32 func_0012E370(void);
long func_0012FEB0(s32, long);
s32 func_01ED7E98(void *, void *, s32);
void func_0015B558(s32);
s32 func_0015B568(void);
void func_0015A080(void);
s32 func_L00_00779A28(Ctx *c, s32 a);

// menu request twin
s32 func_L00_00777358(u8 *arg0, s32 arg1) {
    Req r;
    Ctx *c;
    u8 *g;
    s32 ok;

    r.x0 = D_002218F8[0];
    r.x18 = arg1;
    c = D_002234A4;
    arg0[0x15] = 1;
    c->x0 = 1;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED7E98(&r, D_0015D788, 0));
    g = (u8 *)&D_001721E0;
    ok = 1;
    while (arg0[0x15] != 0) {
        if (func_0015B568() != 0 || *(s32 *)(g + 0x2C4) != 0) {
            c->x10 = 0x66;
            if (c->x14 == 0) {
                c->x14 = 0x66;
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
    arg0[0x15] = 0;
    c->x0 = 0;
    if (ok != 0 && *(s32 *)(arg0 + 0x30) != 0) {
        ok = 0;
    }
    return ok ? *(s32 *)(arg0 + 0x34) : 0;
}
