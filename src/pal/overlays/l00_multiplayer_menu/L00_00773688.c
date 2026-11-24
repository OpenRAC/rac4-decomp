#include "common.h"
#include "pal/global_002234A4.h"

typedef struct Profile {
    u8 pad0[0x128];
    s32 x128;
    u8 pad12C[0x198];
    s32 x2C4;
} Profile;

extern Profile D_001721E0;

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
    u8 pad2C[4];
    char x30[0x20];
    s32 x50;
    u8 pad54[0x70];
} Req;

extern u16 D_002218C8[];
extern u8 D_0015D138[];
extern s32 D_00172818[];

void *func_0011A518(void *, s32, unsigned int);
char *func_0011A9EC(void *, void *);
s32 func_0011AB04(char *);
void func_L00_005C2930(char *dst, char *src, s32 n);
s32 func_0012E370(void);
long func_0012FEB0(s32, long);
s32 func_01ED6CB8(void *, void *, s32);
void func_0015B558(s32);
s32 func_0015B568(void);
void func_0015A080(void);
s32 func_L00_00779A28(Ctx *c, s32 a);

// Sends a request built from arg1, an optional string and arg3, and waits for
// its reply, giving up on an error or a timeout. Maps two reply codes to
// errors. Returns 1 on success, 0 otherwise.
s32 func_L00_00773688(u8 *st, s32 arg1, char *str, s32 arg3) {
    Req r;
    Ctx *c;
    s32 ok;
    s32 v;

    c = D_002234A4;
    func_0011A518(&r, 0, 0xC4);
    ok = 1;
    r.x0 = D_002218C8[0];
    func_0011A9EC(r.x15, c->x64);
    r.x28 = arg1;
    if (str != 0) {
        func_L00_005C2930(r.x30, str, func_0011AB04(str));
    } else {
        r.x30[0] = 0;
    }
    r.x50 = arg3;
    st[2] = 1;
    c->x0 = 1;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED6CB8(&r, D_0015D138, 0));
    while (st[2] != 0) {
        if (func_0015B568() != 0 || D_001721E0.x2C4 != 0) {
            c->x10 = 0x30;
            if (c->x14 == 0) {
                c->x14 = 0x30;
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
    st[2] = 0;
    v = *(s32 *)(st + 0x40);
    if (v == -0x3D2) {
        c->x10 = 0xA;
        if (c->x14 == 0) {
            c->x14 = 0xA;
        }
        ok = 0;
    } else if (v == -0x3B4) {
        D_00172818[0] = 2;
        ok = 0;
    }
    return ok;
}
