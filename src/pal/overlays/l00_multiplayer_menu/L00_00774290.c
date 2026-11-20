#include "common.h"
#include "pal/global_002234A4.h"

typedef struct Ctx {
    u8 pad0[0x10];
    s32 x10;
    s32 x14;
    u8 pad18[0x4C];
    char *x64;
} Ctx;

typedef struct Req {
    u8 pad0[0x14];
    s32 x14;
    u8 pad18[0x8];
} Req;

extern void func_0015B380(void);
extern void func_00161340(s32);
extern void func_00161128(s32);
extern char *func_0011A9EC(char *, char *);
extern s32 func_01ED6258(void *);
extern void func_0015B558(s32);
extern s32 func_0015B568(void);
extern s32 D_00172304[];

// menu request
s32 func_L00_00774290(void) {
    Req req;
    Ctx *c;
    char *id;
    s32 ok;

    ok = 1;
    c = D_002234A4;
    id = c->x64;
    func_0015B380();
    func_00161340(0);
    func_00161128(-1);
    D_00172304[0] = -1;
    func_0011A9EC((char *)&req, id);
    req.x14 = 2;
    func_0015B558(func_01ED6258(&req));
    if (func_0015B568() != 0) {
        c->x10 = 4;
        if (c->x14 == 0) {
            c->x14 = 4;
        }
        ok = 0;
    }
    req.x14 = 1;
    func_0015B558(func_01ED6258(&req));
    if (func_0015B568() != 0) {
        c->x10 = 4;
        if (c->x14 == 0) {
            c->x14 = 4;
        }
        ok = 0;
    }
    return ok;
}
