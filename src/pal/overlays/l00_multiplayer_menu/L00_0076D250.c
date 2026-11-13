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
    char x2C[0x20];
} Req;

extern u16 D_002218A0[];
extern u8 D_0015CD78[];

void func_0011A9EC(void *, void *);
void func_L00_005C2930(char *dst, char *src, s32 n);
s32 func_0012E370(void);
long func_0012FEB0(s32, long);
s32 func_01ED4A18(void *, void *, s32);
void func_0015B558(s32);
s32 func_0015B568(void);
void func_0015A080(void);
s32 func_L00_00779A28(Ctx *c, s32 a);
s32 func_L00_0076CA60(u8 *p, s32 a);

// Sends a network request built from the name at ctx+0x64, arg1 and arg2 through func_01ED4A18, then waits on func_L00_00779A28 until it ends; error codes go to ctx+0x10/0x14.
s32 func_L00_0076D250(u8 *arg0, s32 arg1, char *arg2) {
    Req r;
    Ctx *c;
    u8 *g;
    s32 ok;
    s32 v;
    char *name;

    c = D_002234A4;
    name = c->x64;
    r.x0 = D_002218A0[0];
    func_0011A9EC(r.x15, name);
    r.x28 = arg1;
    func_L00_005C2930(r.x2C, arg2, 0x20);
    arg0[0x70] = 1;
    c->x0 = 1;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED4A18(&r, D_0015CD78, 0));
    g = (u8 *)&D_001721E0;
    ok = 1;
    while (arg0[0x70] != 0) {
        if (func_0015B568() != 0 || *(s32 *)(g + 0x2C4) != 0) {
            c->x10 = 0x16;
            if (c->x14 == 0) {
                c->x14 = 0x16;
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
    arg0[0x70] = 0;
    if (ok != 0) {
        v = *(s32 *)(arg0 + 0x74);
        if (v == -0x3DE) {
            v = 0x23;
        } else if (v != 0) {
            v = 0x17;
        } else {
            goto skip;
        }
        c->x10 = v;
        if (c->x14 == 0) {
            c->x14 = v;
        }
        ok = 0;
    skip:
        if (ok != 0) {
            ok = func_L00_0076CA60(arg0, 0);
        }
    }
    return ok;
}
