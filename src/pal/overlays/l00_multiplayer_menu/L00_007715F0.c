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
    s32 x1C;
    s32 x20;
    u8 pad24[0xC];
} Req;

extern u16 D_002218A0[];
extern u8 D_0015CFA8[];

s32 func_0012E370(void);
long func_0012FEB0(s32, long);
s32 func_01ED5428(void *, void *, s32);
void func_0015B558(s32);
s32 func_0015B568(void);
void func_0015A080(void);
s32 func_L00_00779A28(Ctx *c, s32 a);

// Sends a request and waits for its reply, giving up on an error or a
// timeout. Returns the reply buffer, or NULL on failure.
u8 *func_L00_007715F0(s32 *arg0, s32 arg1, s32 arg2) {
    Req r;
    Ctx *c;
    u8 *g;
    s32 ok;
    u8 *res;

    c = D_002234A4;
    if (arg0[0] == -1) {
        return NULL;
    }
    r.x0 = D_002218A0[0];
    r.x18 = arg0[0];
    r.x1C = arg1;
    r.x20 = arg2;
    ((u8 *)arg0)[0x3A8] = 1;
    c->x0 = 1;
    ok = 1;
    res = (u8 *)arg0 + 0x3AC;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED5428(&r, D_0015CFA8, 0));
    g = (u8 *)&D_001721E0;
    while (((u8 *)arg0)[0x3A8] != 0) {
        if (func_0015B568() != 0 || *(s32 *)(g + 0x2C4) != 0) {
            c->x10 = 0x25;
            if (c->x14 == 0) {
                c->x14 = 0x25;
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
    ((u8 *)arg0)[0x3A8] = 0;
    if (ok != 0 && arg0[0xF3] != 0) {
        c->x10 = 0x25;
        if (c->x14 == 0) {
            c->x14 = 0x25;
        }
        ok = 0;
    }
    return ok ? res : NULL;
}
