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
    void *x68;
} Ctx;

typedef struct Req {
    u16 x0;
    u8 pad2[0x13];
    char x15[0x13];
    s32 x28;
    char x2C[0x20];
    char x4C[0x20];
    u8 pad6C[0x4];
} Req;

extern u16 D_00221878[];
extern u8 D_0015CB98[];

s32 func_L00_00780F40(void *, char *, s32);
char *func_0011A9EC(void *, void *);
void func_L00_005C2930(char *dst, char *src, s32 n);
s32 func_0012E370(void);
long func_0012FEB0(s32, long);
s32 func_01ED6910(void *, void *, s32);
void func_0015B558(s32);
s32 func_0015B568(void);
void func_0015A080(void);
s32 func_L00_00779A28(Ctx *c, s32 a);

// Add PAL C for func_L00_0076A2C0
s32 func_L00_0076A2C0(u8 *st, char *name, char *pass) {
    Req r;
    Ctx *c;
    void *p;
    u8 *g;
    s32 ok;
    s32 v;
    s32 e;

    c = D_002234A4;
    p = c->x68;
    if (func_L00_00780F40(p, name, 0) == 0 || func_L00_00780F40(p, pass, 0) == 0) {
        c->x10 = 3;
        if (c->x14 == 0) {
            c->x14 = 3;
        }
        return 0;
    }
    r.x0 = D_00221878[0];
    func_0011A9EC(r.x15, c->x64);
    r.x28 = 1;
    func_L00_005C2930(r.x2C, name, 0x20);
    func_L00_005C2930(r.x4C, pass, 0x20);
    st[0x29] = 1;
    c->x0 = 1;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED6910(&r, D_0015CB98, 0));
    g = (u8 *)&D_001721E0;
    ok = 1;
    while (st[0x29] != 0) {
        if (func_0015B568() != 0 || *(s32 *)(g + 0x2C4) != 0) {
            c->x10 = 0xC;
            if (c->x14 == 0) {
                c->x14 = 0xC;
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
    st[0x29] = 0;
    if (ok != 0) {
        v = *(s32 *)(st + 0x48);
        if (v != 0) {
            if (v == -0x3E7) {
                c->x10 = 0xE;
                if (c->x14 == 0) {
                    c->x14 = 0xE;
                }
            } else {
                c->x10 = 0xC;
                if (c->x14 == 0) {
                    c->x14 = 0xC;
                }
            }
            ok = 0;
        }
    }
    if (ok != 0) {
        c->x10 = 0;
        c->x14 = 0;
    }
    return ok;
}
