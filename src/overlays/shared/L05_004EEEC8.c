#include "common.h"

typedef struct {
    u8 pad0[0x3C];
    u8 *moby;
} Target;

extern Target D_0023F300[];

extern void func_0056D8F8(u8 *, u8 *);
extern s32 func_005340D0(s16 *);
extern u8 *func_0056AF78(u8 *, s32, s32);
extern void func_0056D6D0(u8 *, s32, s32, s32);
extern void func_005FD288(s32, s32, u8 *);
extern void func_00568B98(u8 *, s32, s32);

s32 func_L05_004EEEC8(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    u8 *hit;
    s32 dmg;

    func_0056D8F8(moby, vars + 0xE0);
    func_005340D0((s16 *)(vars + 0x7A));
    if (moby[0x2C] == 0xFF || (&D_0023F300[0] + moby[0x2C])->moby != moby) {
        hit = NULL;
    } else {
        hit = func_0056AF78(moby, 0x1800, 0);
    }
    if (hit != NULL && *(s16 *)(vars + 0x7A) == 0) {
        dmg = *(f32 *)(hit + 0x2C);
        *(s16 *)(vars + 0x7A) = 0xA;
        *(f32 *)(vars + 0x50) -= dmg;
        func_0056D6D0(moby, 1, 0, 0);
        func_005FD288(1, 0, moby);
    }
    moby[0x2C] = 0xFF;
    if (*(f32 *)(vars + 0x50) <= 0.0f) {
        func_00568B98(moby, 5, -1);
    }
    return 0;
}
