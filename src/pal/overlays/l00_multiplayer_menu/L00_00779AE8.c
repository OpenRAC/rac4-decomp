#include "common.h"
#include "pal/profile_001721E0.h"

typedef struct Ctx {
    u8 pad0[0x10];
    s32 x10;
    s32 x14;
    u8 pad18[0x20];
    void *x38;
    void *x3C;
    void *x40;
    void *x44;
    s32 x48;
    void *x4C;
    void *x50;
    void *x54;
    void *x58;
    u8 pad5C[4];
    void *x60;
    u8 *x64;
    void *x68;
    u8 pad6C[0x1C];
    s32 x88;
    s32 x8C;
} Ctx;

s32 func_0015B568(void);
s32 func_00161350(void);
s32 func_00161138(void);
s32 func_L00_00781B00(void *);
s32 func_L00_0076B530(void *);
s32 func_L00_0076E638(void *);
s32 func_L00_00771C50(void *);
s32 func_L00_00774D78(s32);
s32 func_L00_00775B18(void *);
s32 func_L00_00775FB0(void *);
s32 func_L00_00776BE8(void *);
s32 func_L00_00778488(void *);
s32 func_L00_0077AC90(void *);
s32 func_L00_0077CE68(void *);

static inline u8 *profile(void) {
    return (u8 *)&D_001721E0;
}

// Add PAL C for func_L00_00779AE8
s32 func_L00_00779AE8(Ctx *c) {
    s32 ok;
    s32 busy;
    u8 *p;

    ok = 1;
    if (profile()[0x2D4] == 0) {
        return 0;
    }
    if (func_0015B568() != 0) {
        c->x10 = 8;
        if (c->x14 == 0) {
            c->x14 = 8;
        }
        ok = 0;
    }
    if (*(s32 *)(profile() + 0x2C4) != 0) {
        c->x88++;
    } else {
        c->x88 = 0;
    }
    if (c->x88 >= 0x3D) {
        c->x10 = 8;
        if (c->x14 == 0) {
            c->x14 = 8;
        }
        ok = 0;
    }
    if (func_00161350() != 0) {
        if (*(s32 *)(profile() + 0x2C0) != 0) {
            c->x8C++;
        } else {
            c->x8C = 0;
        }
        if (c->x8C >= 0x3D) {
            c->x10 = 8;
            if (c->x14 == 0) {
                c->x14 = 8;
            }
            ok = 0;
        }
    }
    busy = 0;
    if (ok != 0) {
        p = c->x64;
        if (p != 0) {
            u8 r = 0;
            if (p[0x11E] == 0 || p[0x175] != 0) {
                r = 1;
            }
            busy = r;
        }
    }
    if (busy == 0) {
        if (ok != 0 && c->x68 != 0) {
            ok = func_L00_00781B00(c->x68);
        }
        if (ok != 0 && c->x38 != 0) {
            ok = func_L00_0076B530(c->x38);
        }
        if (ok != 0 && c->x3C != 0) {
            ok = func_L00_0076E638(c->x3C);
        }
        if (ok != 0 && c->x40 != 0) {
            ok = func_L00_00771C50(c->x40);
        }
        if (ok != 0 && c->x48 != 0 && ~func_00161138() != 0) {
            ok = func_L00_00774D78(c->x48);
        }
        if (ok != 0 && c->x44 != 0) {
            ok = func_L00_00775B18(c->x44);
        }
        if (ok != 0 && c->x4C != 0) {
            ok = func_L00_00775FB0(c->x4C);
        }
        if (ok != 0 && c->x50 != 0) {
            ok = func_L00_00776BE8(c->x50);
        }
        if (ok != 0 && c->x54 != 0) {
            ok = func_L00_00778488(c->x54);
        }
        if (ok != 0 && c->x58 != 0) {
            ok = func_L00_0077AC90(c->x58);
        }
        if (ok != 0 && c->x60 != 0) {
            ok = func_L00_0077CE68(c->x60);
        }
    }
    return ok;
}
