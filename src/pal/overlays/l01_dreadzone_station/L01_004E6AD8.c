#include "common.h"

typedef struct {
    u8 pad0[0x3C];
    u8 *moby;
} Target;

extern Target D_002424C0[];

extern void func_00477AD0(u8 *, u8 *);
extern s32 func_L01_004E6E08(u8 *);
extern s32 func_00453D20(s16 *);
extern u8 *func_004756A8(u8 *, s32, s32);
extern void func_004778A8(u8 *, s32, s32, s32);

// Like func_L05_004F0B20 for a target that can be switched off: unless func_L01_004E6E08 says so
// or the byte at vars+0xF4 is 0 (then flag 0x1000 is cleared), it sets flag 0x1000 and, on a hit
// from the moby in slot +0x2C of D_002424C0, restarts a 4-frame cooldown and takes the hit's +0x2C
// (as a whole number) from the health at vars+0x50. Returns 0.
s32 func_L01_004E6AD8(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    u8 *hit;
    s32 dmg;

    func_00477AD0(moby, vars + 0xE0);
    if (func_L01_004E6E08(moby) != 0 || vars[0xF4] == 0) {
        *(u16 *)(moby + 0x34) &= 0xEFFF;
        return 0;
    }
    *(u16 *)(moby + 0x34) |= 0x1000;
    func_00453D20((s16 *)(vars + 0x7A));
    if (moby[0x2C] == 0xFF || (&D_002424C0[0] + moby[0x2C])->moby != moby) {
        hit = NULL;
    } else {
        hit = func_004756A8(moby, 0x1800, 0);
    }
    if (hit != NULL && *(s16 *)(vars + 0x7A) == 0) {
        dmg = *(f32 *)(hit + 0x2C);
        *(s16 *)(vars + 0x7A) = 4;
        *(f32 *)(vars + 0x50) -= dmg;
        func_004778A8(moby, 1, 0, 0);
    }
    moby[0x2C] = 0xFF;
    return 0;
}
