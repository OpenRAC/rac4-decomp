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
    u8 pad1D[0x17];
    s32 *x34;
    u8 pad38[0x2C];
    char *x64;
} Ctx;

typedef struct Req {
    u8 x0[0x15];
    char x15[0x13];
    s32 x28;
    u8 pad2C[4];
} Req;

extern char D_00221960[];
extern u8 D_0015D2F0[];
extern s32 D_0021DAE4;
extern s32 D_0021DAE8;
extern u8 D_0021DAEC;

extern s32 func_0011D920(char *, const char *, ...);
char *func_0011A9EC(void *, void *);
s32 func_0012E370(void);
long func_0012FEB0(s32, long);
s32 func_01ED6EC8(void *, void *, s32);
void func_0015B558(s32);
s32 func_0015B568(void);
void func_0015A080(void);
s32 func_L00_00779A28(Ctx *c, s32 a);

// Add PAL C for func_L00_0077BAC0
u8 *func_L00_0077BAC0(u8 *st, s32 id) {
    Req r;
    Ctx *c;
    char *name;
    u8 *g;
    u8 *info;
    u8 *p;
    u8 *res;
    s32 ok;
    s32 v;
    s32 e;
    s32 crc;
    s32 poly;
    s32 i;

    c = D_002234A4;
    name = c->x64;
    func_0011D920((char *)r.x0, D_00221960, 0);
    func_0011A9EC(r.x15, name);
    r.x28 = id;
    st[0] = 1;
    c->x0 = 1;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED6EC8(&r, D_0015D2F0, 0));
    g = (u8 *)&D_001721E0;
    ok = 1;
    while (st[0] != 0) {
        if (func_0015B568() != 0 || *(s32 *)(g + 0x2C4) != 0) {
            c->x10 = 0x46;
            if (c->x14 == 0) {
                c->x14 = 0x46;
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
    st[0] = 0;
    res = 0;
    if (ok != 0) {
        poly = 0xF12477CD;
        v = *(s32 *)(st + 0x1C);
        if (v == -0x3DD) {
            e = 0x45;
        } else if (v == 0) {
            goto skip;
        } else {
            e = 0x46;
        }
        c->x10 = e;
        if (c->x14 == 0) {
            c->x14 = e;
        }
        ok = 0;
    }
skip:
    if (ok != 0) {
        res = st + 4;
        if (*c->x34 == id) {
            info = st + 0x4C;
            crc = -1;
            poly = ~poly << 4;
            for (p = info; p < info + 0x28; p++) {
                crc ^= *p;
                for (i = 7; i >= 0; i--) {
                    if (crc & 1) {
                        crc = (crc >> 1) ^ poly;
                    } else {
                        crc >>= 1;
                    }
                }
            }
            crc ^= 0x1725DFAD;
            D_0021DAE4 = *(s32 *)(info + 0x28) ^ (crc & 0xFFFF);
            D_0021DAE8 = *(s32 *)(info + 0x2C) ^ ((u32)crc >> 16);
            D_0021DAEC = (info[0x30] ^ (crc & 0xFF)) == 0;
        }
    }
    return res;
}
