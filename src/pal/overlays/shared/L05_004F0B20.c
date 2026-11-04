#include "common.h"

typedef struct {
    u8 pad0[0x3C];
    u8 *moby;
} Target;

extern Target D_0023F400[];

extern void func_00477AD0(u8 *, u8 *);
extern s32 func_00453D20(s16 *);
extern u8 *func_004756A8(u8 *, s32, s32);
extern void func_004778A8(u8 *, s32, s32, s32);
extern void func_004E2EF0(s32, s32, u8 *);
extern void func_00474368(u8 *, s32, s32);

// Per-frame update of a target that can be hit: when the moby in slot +0x2C of D_0023F400 is
// this one and func_004756A8 reports a hit (and the cooldown at vars+0x7A is over), it restarts the
// cooldown at 8 frames, takes the hit's +0x2C (as a whole number) from the health at vars+0x50 and
// plays its reactions. When the health reaches 0 it goes to state 5. Returns 0.
s32 func_L05_004F0B20(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    u8 *hit;
    s32 dmg;

    func_00477AD0(moby, vars + 0xE0);
    func_00453D20((s16 *)(vars + 0x7A));
    if (moby[0x2C] == 0xFF || (&D_0023F400[0] + moby[0x2C])->moby != moby) {
        hit = NULL;
    } else {
        hit = func_004756A8(moby, 0x1800, 0);
    }
    if (hit != NULL && *(s16 *)(vars + 0x7A) == 0) {
        dmg = *(f32 *)(hit + 0x2C);
        *(s16 *)(vars + 0x7A) = 8;
        *(f32 *)(vars + 0x50) -= dmg;
        func_004778A8(moby, 1, 0, 0);
        func_004E2EF0(1, 0, moby);
    }
    moby[0x2C] = 0xFF;
    if (*(f32 *)(vars + 0x50) <= 0.0f) {
        func_00474368(moby, 5, -1);
    }
    return 0;
}
