#include "common.h"

typedef struct {
    u8 pad0[0x3C];
    u8 *moby;
} Target;

extern Target D_002423C0[];

extern void func_004771B0(u8 *, u8 *);
extern s32 func_L01_004E4E50(u8 *);
extern s32 func_00453508(s16 *);
extern u8 *func_00474DD0(u8 *, s32, s32);
extern void func_00476F88(u8 *, s32, s32, s32);

s32 func_L01_004E4B20(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    u8 *hit;
    s32 dmg;

    func_004771B0(moby, vars + 0xE0);
    if (func_L01_004E4E50(moby) != 0 || vars[0xF4] == 0) {
        *(u16 *)(moby + 0x34) &= 0xEFFF;
        return 0;
    }
    *(u16 *)(moby + 0x34) |= 0x1000;
    func_00453508((s16 *)(vars + 0x7A));
    if (moby[0x2C] == 0xFF || (&D_002423C0[0] + moby[0x2C])->moby != moby) {
        hit = NULL;
    } else {
        hit = func_00474DD0(moby, 0x1800, 0);
    }
    if (hit != NULL && *(s16 *)(vars + 0x7A) == 0) {
        dmg = *(f32 *)(hit + 0x2C);
        *(s16 *)(vars + 0x7A) = 0x5;
        *(f32 *)(vars + 0x50) -= dmg;
        func_00476F88(moby, 1, 0, 0);
    }
    moby[0x2C] = 0xFF;
    return 0;
}
