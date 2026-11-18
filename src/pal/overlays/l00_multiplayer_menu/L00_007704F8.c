#include "common.h"
#include "pal/global_002234A4.h"

typedef struct Ctx {
    u8 pad0[0x64];
    char *x64;
} Ctx;

typedef struct Req {
    u16 x0;
    u8 pad2[0x13];
    char x15[0x13];
    s32 x28;
    s32 x2C;
    s32 x30;
    s32 x34;
    s32 x38;
    u8 pad3C[0x4];
} Req;

extern u16 D_002218A0[];
extern char *func_0011A9EC(char *, char *);
extern s32 func_0012E370(void);
extern s64 func_0012FEB0(s32, s64);
extern void func_0015CE18(void);
extern s32 func_01ED5118(void *, void *, s32);
extern void func_0015B558(s32);
extern s32 func_0015B568(void);

// menu request
s32 func_L00_007704F8(u8 *obj, s32 mode, s32 arg2) {
    Req req;
    s32 ok;
    char *name;

    ok = 1;
    if (obj[0x4F8] != 0) {
        name = ((Ctx *)D_002234A4)->x64;
        *(s32 *)(obj + 0x4F4) = arg2;
        obj[0x4F0] = mode;
        req.x0 = D_002218A0[0];
        func_0011A9EC(req.x15, name);
        req.x28 = *(s32 *)(obj + 0x0);
        req.x2C = ok;
        req.x30 = *(s32 *)(obj + 0x50C);
        req.x34 = *(s32 *)(obj + 0x4F4);
        req.x38 = mode;
        obj[0x500] = ok;
        *(s32 *)(obj + 0x504) = func_0012FEB0(func_0012E370(), 0x24000);
        func_0015B558(func_01ED5118(&req, func_0015CE18, 0));
        if (func_0015B568() != 0) {
            ok = 0;
        }
    }
    return ok;
}
