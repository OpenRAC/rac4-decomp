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
    char x15[0x11];
    char x26[0x20];
    char x46[0x20];
    u8 pad66[0xA];
} Req;

extern u16 D_00221878[];
extern u8 D_0015CC10[];

char *func_0011AFC8(void *, void *, s32);
char *func_0011A9EC(void *, void *);
s32 func_0011AB04(char *);
void func_L00_005C2930(char *dst, char *src, s32 n);
s32 func_0012E370(void);
long func_0012FEB0(s32, long);
s32 func_01ED6478(void *, void *, s32);
void func_0015B558(s32);
s32 func_0015B568(void);
void func_0015A080(void);
s32 func_L00_00779A28(Ctx *c, s32 a);

// Add PAL C for func_L00_0076AC00
s32 func_L00_0076AC00(u8 *st, char *name, char *pass) {
    Req r;
    Ctx *c;
    u8 *g;
    s32 ok;
    s32 v;

    c = D_002234A4;
    func_0011AFC8(st + 4, name, 0x20);
    st[0x23] = 0;
    r.x0 = D_00221878[0];
    func_0011A9EC(r.x15, c->x64);
    func_L00_005C2930(r.x26, (char *)(st + 4), func_0011AB04((char *)(st + 4)));
    func_L00_005C2930(r.x46, pass, 0x20);
    st[0x2C] = 1;
    c->x0 = 1;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED6478(&r, D_0015CC10, 0));
    g = (u8 *)&D_001721E0;
    ok = 1;
    while (st[0x2C] != 0) {
        if (func_0015B568() != 0 || *(s32 *)(g + 0x2C4) != 0) {
            c->x10 = 9;
            if (c->x14 == 0) {
                c->x14 = 9;
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
    st[0x2C] = 0;
    if (ok != 0 && *(s32 *)(st + 0x68) != 0) {
        c->x10 = 9;
        if (c->x14 == 0) {
            c->x14 = 9;
        }
        ok = 0;
    }
    if (ok != 0) {
        v = *(s32 *)(st + 0x6C);
        *(s32 *)st = v;
        *(s32 *)&D_001721E0.region20.bytes[0x14] = v;
        c->x10 = 0;
        c->x14 = 0;
    }
    return ok;
}
