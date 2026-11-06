#include "common.h"

extern void func_00549560(s32, s32, s32);
extern void func_00415F40(s32, u8 *, s32);
extern u8 *func_0054A290(s32, s32);
extern s32 func_0054BCF0(s32, s32, s32);
extern void func_00474368(u8 *, s32, s32);

// When the moby has a player at vars+0xC: calls func_00549560 and func_00415F40 for it, then
// takes speed +0x4C of entry (6, 0) from func_0054A290, lowers it 5 % per level that
// func_0054BCF0 reports and doubles it, stores speed * 50 (maybe a 50 Hz frame count) and 85 % of that at
// +4/+6 and the speed at +0x3EC of the player, clears +0 and sets state 6.
void func_0041E390(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    u8 *v;
    f32 speed;
    s32 n;
    s32 id;

    if (*(u8 **)(vars + 0xC) != NULL) {
        id = *(s32 *)(vars + 0);
        func_00549560(*(s32 *)(*(u8 **)(vars + 0xC) + 0x26E4), 6, 1);
        func_00415F40(id, *(u8 **)(vars + 0xC), 1);
        v = *(u8 **)(moby + 0xAC);
        speed = *(f32 *)(func_0054A290(6, 0) + 0x4C);
        n = func_0054BCF0(*(s32 *)(*(u8 **)(v + 0xC) + 0x26E4), 6, 1);
        if (n != 0) {
            speed *= 1.0f - n * 0.05f;
        }
        speed *= 2.0f;
        *(s16 *)(v + 6) = (*(s16 *)(v + 4) = speed * 50.0f) * 0.85f;
        *(f32 *)(*(u8 **)(v + 0xC) + 0x3EC) = speed;
        *(s32 *)(vars + 0) = 0;
        func_00474368(moby, 6, -1);
    }
}
