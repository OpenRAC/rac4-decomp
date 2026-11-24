#include "common.h"
#include "pal/global_002234A4.h"

typedef struct Sub {
    u8 pad0[0x5];
    u8 x5;
    u8 pad6[0xE];
    u8 x14;
    u8 pad15[0x153];
    u8 x168;
} Sub;

typedef struct Ctx {
    u8 x0;
    u8 pad1[7];
    s32 x8;
    u8 padC[4];
    s32 x10;
    s32 x14;
    u8 pad18[4];
    u8 x1C;
    u8 pad1D[0x27];
    Sub *x44;
    Sub *x48;
    u8 pad4C[0x14];
    Sub *x60;
    char *x64;
} Ctx;

typedef struct Req {
    u16 x0;
    u8 pad2[0x13];
    char x15[0x1B];
} Req;

typedef struct Profile {
    u8 pad0[0x34];
    s32 x34;
    u8 pad38[0x28C];
    s32 x2C4;
} Profile;

extern Profile D_001721E0;
extern u16 D_00221878[];
extern u8 D_0015CC38[];

char *func_0011A9EC(char *, char *);
s32 func_0012E370(void);
long func_0012FEB0(s32, long);
s32 func_01ED6718(void *, void *, s32);
void func_0015B558(s32);
s32 func_0015B568(void);
void func_0015A080(void);
s32 func_L00_00779A28(Ctx *c, s32 a);

// Sends a request and waits for its reply, giving up on an error or a
// timeout (error 0xB); a set x12C also fails unless flag is set. Then clears
// the request state and returns whether it succeeded.
s32 func_L00_0076ADB8(u8 *st, s32 flag) {
    Req r;
    Ctx *c;
    s32 ok;

    r.x0 = D_00221878[0];
    c = D_002234A4;
    func_0011A9EC(r.x15, c->x64);
    st[0x2D] = 1;
    c->x0 = 1;
    ok = 1;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED6718(&r, D_0015CC38, 0));
    while (st[0x2D] != 0) {
        if (func_0015B568() != 0 || D_001721E0.x2C4 != 0) {
            c->x10 = 0xB;
            if (c->x14 == 0) {
                c->x14 = 0xB;
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
    st[0x2D] = 0;
    if (ok != 0) {
        if (*(s32 *)(st + 0x12C) != 0 && flag == 0) {
            c->x10 = 0xB;
            if (c->x14 == 0) {
                c->x14 = 0xB;
            }
            ok = 0;
        }
        if (flag != 0) {
            func_0015B558(0);
        }
        if (ok != 0) {
            c->x10 = 0;
            c->x14 = 0;
        }
    }
    c->x60->x168 = 0;
    c->x44->x14 = 0;
    c->x48->x5 = 0;
    *(s32 *)st = -1;
    D_001721E0.x34 = -1;
    return ok;
}
