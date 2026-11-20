#include "common.h"
#include "pal/global_002234A4.h"

typedef struct Ctx {
    u8 x0;
    u8 pad1[0x7];
    s32 x8;
    u8 padC[0x4];
    s32 x10;
    s32 x14;
    u8 pad18[0x4C];
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
extern s32 D_00172304[];
extern char *func_0011A9EC(char *, char *);
extern s32 func_0012E370(void);
extern s64 func_0012FEB0(s32, s64);
extern void func_0015D1D8(void);
extern s32 func_01ED6F48(void *, void *, s32);
extern void func_0015B558(s32);
extern s32 func_0015B568(void);

// menu request
s32 func_L00_00774378(u8 *st) {
    Req req;
    Ctx *c;
    s32 ok;

    req.x0 = D_002218C8[0];
    ok = 1;
    c = D_002234A4;
    func_0011A9EC(req.x15, c->x64);
    req.x28 = D_00172304[0];
    st[4] = 1;
    *(s32 *)(st + 0xC) = func_0012FEB0(func_0012E370(), 0x24000);
    c->x0 = 1;
    c->x8 = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED6F48(&req, func_0015D1D8, 0));
    if (func_0015B568() != 0) {
        c->x10 = 0x38;
        if (c->x14 == 0) {
            c->x14 = 0x38;
        }
        ok = 0;
    }
    c->x0 = 0;
    return ok;
}
