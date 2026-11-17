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
    s32 x2C;
    char x30[0x40];
    char x70[0x20];
    s32 x90;
    s32 x94;
    s32 x98;
    s32 x9C;
    s32 xA0;
} Req;

extern u16 D_00221970[];
extern u8 D_0015D368[];

void *func_0011A518(void *, s32, unsigned int);
char *func_0011A9EC(void *, void *);
s32 func_00146D10(void);
void func_L00_005C2930(char *dst, char *src, s32 n);
s32 func_0012E370(void);
long func_0012FEB0(s32, long);
s32 func_01ED6C30(void *, void *, s32);
void func_0015B558(s32);
s32 func_0015B568(void);
void func_0015A080(void);
s32 func_L00_00779A28(Ctx *c, s32 a);

// Add PAL C for func_L00_0077C8F8
s32 func_L00_0077C8F8(u8 *st, u8 *info, s32 *out) {
    Req r;
    Ctx *c;
    char *name;
    u8 *g;
    s32 ok;
    s32 v;
    s32 e;

    c = D_002234A4;
    name = c->x64;
    func_0011A518(&r, 0, 0xA4);
    r.x0 = D_00221970[0];
    func_0011A9EC(r.x15, name);
    r.x28 = func_00146D10();
    r.x2C = *(s32 *)(info + 0x60);
    r.x90 = *(s32 *)(info + 0x64);
    r.x94 = *(s32 *)(info + 0x68);
    r.x98 = *(s32 *)(info + 0x6C);
    r.x9C = *(s32 *)(info + 0x70);
    r.xA0 = *(s32 *)(info + 0x74);
    func_L00_005C2930(r.x30, (char *)info, 0x40);
    func_L00_005C2930(r.x70, (char *)(info + 0x40), 0x20);
    st[0xC0] = 1;
    c->x0 = 1;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED6C30(&r, D_0015D368, 0));
    g = (u8 *)&D_001721E0;
    ok = 1;
    while (st[0xC0] != 0) {
        if (func_0015B568() != 0 || *(s32 *)(g + 0x2C4) != 0) {
            c->x10 = 0x4A;
            if (c->x14 == 0) {
                c->x14 = 0x4A;
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
    st[0xC0] = 0;
    if (ok != 0) {
        v = *(s32 *)(st + 0xDC);
        if (v == -0x3DD) {
            e = 0x4B;
        } else if (v == 3 || v == 0) {
            goto skip;
        } else {
            if (*(s32 *)(info + 0x64) == 6 && v == -0x3CE) {
                goto skip;
            }
            e = 0x4A;
        }
        c->x10 = e;
        if (c->x14 == 0) {
            c->x14 = e;
        }
        ok = 0;
    }
skip:
    if (out != 0) {
        if (ok != 0 || *(s32 *)(st + 0xDC) == -0x3CE) {
            *out = *(s32 *)(st + 0xE0);
        } else {
            *out = -1;
        }
    }
    return ok;
}
