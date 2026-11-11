#include "common.h"

typedef struct {
    u8 pad0[0x3C];
    u8 *moby;
} Target;

typedef struct {
    u8 pad0[0x18];
    u8 *last;
    u8 pad1C[8];
    s16 timer;
} Hits;

extern Target D_0023EE80[];

extern void func_00541E10(u8 *, u8 *);
extern s32 func_00508988(s16 *);
extern u8 *func_0053F490(u8 *, s32, s32);
extern s32 func_00492888(u8 *);
extern void func_00541BE8(u8 *, s32, s32, s32);

f32 func_L11_00492768(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    Hits *h;
    u8 *hit;

    func_00541E10(moby, NULL);
    h = (Hits *)(vars + 0x50);
    if (h->last != NULL) {
        if (h->last[0x20] == 0xFE) {
            goto clear;
        }
        if (h->last[0x20] == 0xFD) {
            goto clear;
        }
    }
    if (func_00508988((s16 *)(vars + 0x74)) != 0) {
    clear:
        h->last = NULL;
    }
    if (moby[0x2C] == 0xFF || (&D_0023EE80[0] + moby[0x2C])->moby != moby) {
        hit = NULL;
    } else {
        hit = func_0053F490(moby, 0x0FFFFFFF, 0);
    }
    moby[0x2C] = 0xFF;
    if (hit != NULL && *(u8 **)(hit + 0x20) != NULL && func_00492888(*(u8 **)(hit + 0x20)) != 0 &&
        h->last != *(u8 **)(hit + 0x20)) {
        h->last = *(u8 **)(hit + 0x20);
        h->timer = 0x78;
        func_00541BE8(moby, 1, 0, 0);
        return *(f32 *)(hit + 0x2C);
    }
    return 0.0f;
}
