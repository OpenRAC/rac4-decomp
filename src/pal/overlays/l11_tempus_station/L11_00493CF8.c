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

extern Target D_0023EF00[];

extern void func_00477AD0(u8 *, u8 *);
extern s32 func_00453D20(s16 *);
extern u8 *func_004756A8(u8 *, s32, s32);
extern s32 func_L11_00493E18(u8 *);
extern void func_004778A8(u8 *, s32, s32, s32);

// Hit check that remembers the last attacker (vars+0x68): it forgets it when that moby is gone
// (state 0xFE/0xFD) or the timer at vars+0x74 runs out. On a hit from the moby in slot +0x2C of
// D_0023EF00 whose attacker passes func_L11_00493E18 and is not the remembered one, it remembers it
// for 100 frames, plays the reaction and returns the hit's damage (+0x2C); otherwise 0.
f32 func_L11_00493CF8(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    Hits *h;
    u8 *hit;

    func_00477AD0(moby, NULL);
    h = (Hits *)(vars + 0x50);
    if (h->last != NULL) {
        if (h->last[0x20] == 0xFE) {
            goto clear;
        }
        if (h->last[0x20] == 0xFD) {
            goto clear;
        }
    }
    if (func_00453D20((s16 *)(vars + 0x74)) != 0) {
    clear:
        h->last = NULL;
    }
    if (moby[0x2C] == 0xFF || (&D_0023EF00[0] + moby[0x2C])->moby != moby) {
        hit = NULL;
    } else {
        hit = func_004756A8(moby, 0x0FFFFFFF, 0);
    }
    moby[0x2C] = 0xFF;
    if (hit != NULL && *(u8 **)(hit + 0x20) != NULL && func_L11_00493E18(*(u8 **)(hit + 0x20)) != 0 &&
        h->last != *(u8 **)(hit + 0x20)) {
        h->last = *(u8 **)(hit + 0x20);
        h->timer = 100;
        func_004778A8(moby, 1, 0, 0);
        return *(f32 *)(hit + 0x2C);
    }
    return 0.0f;
}
