#include "common.h"

extern void func_L06_00401828(u8 *);
extern f32 func_L06_00401AE8(u8 *);
extern s32 func_004E28D8(u8 *, s32);
extern s16 func_004E2EF0(s32, s32, u8 *);
extern void func_004E2A48(s32);
extern void func_004763B0(f32 *, f32 *, f32, f32, f32, f32);
extern void func_L06_00401B40(u8 *, f32);
extern void func_L06_00401BE0(u8 *);
extern void func_00474368(u8 *, s32, s32);

// Per-frame update of an object whose level at vars+4 follows a target at vars+8 (smoothed by
// func_004763B0 with 0.0144, 0.0144, 0.06): state 1 takes the target from func_L06_00401AE8 and
// keeps one func_004E2EF0(0, 4) handle at vars+0x18 alive while the level moves (dropped with
// func_004E2A48 when it reaches it); state 2 goes to 3 once the level is at or below the target,
// state 4 goes to 5 once it is at or above it; state 3 only calls func_L06_00401BE0.
void func_L06_00401610(u8 *moby) {
    u8 *vars;
    f32 t;

    if (*(u8 **)(moby + 0xAC) == NULL) {
        return;
    }
    if (moby[0x20] == 0) {
        func_L06_00401828(moby);
    }
    vars = *(u8 **)(moby + 0xAC);
    switch (moby[0x20]) {
    case 1:
        t = func_L06_00401AE8(moby);
        *(f32 *)(vars + 8) = t;
        if (*(f32 *)(vars + 4) != t) {
            if (*(s16 *)(vars + 0x18) != -1 && func_004E28D8(moby, *(s16 *)(vars + 0x18)) == 0) {
                *(s16 *)(vars + 0x18) = -1;
            }
            if (*(s16 *)(vars + 0x18) == -1) {
                *(s16 *)(vars + 0x18) = func_004E2EF0(0, 4, moby);
            }
        } else if (*(s16 *)(vars + 0x18) != -1) {
            func_004E2A48(*(s16 *)(vars + 0x18));
            *(s16 *)(vars + 0x18) = -1;
        }
        func_004763B0((f32 *)(vars + 4), (f32 *)(vars + 0xC), *(f32 *)(vars + 8), 0.014400001f, 0.014400001f, 0.060000002f);
        func_L06_00401B40(moby, *(f32 *)(vars + 4));
        func_L06_00401BE0(moby);
        break;
    case 2:
        func_004763B0((f32 *)(vars + 4), (f32 *)(vars + 0xC), *(f32 *)(vars + 8), 0.014400001f, 0.014400001f, 0.060000002f);
        func_L06_00401B40(moby, *(f32 *)(vars + 4));
        func_L06_00401BE0(moby);
        if (*(f32 *)(vars + 4) <= *(f32 *)(vars + 8)) {
            func_00474368(moby, 3, -1);
        }
        break;
    case 3:
        func_L06_00401BE0(moby);
        break;
    case 4:
        func_004763B0((f32 *)(vars + 4), (f32 *)(vars + 0xC), *(f32 *)(vars + 8), 0.014400001f, 0.014400001f, 0.060000002f);
        func_L06_00401B40(moby, *(f32 *)(vars + 4));
        func_L06_00401BE0(moby);
        if (*(f32 *)(vars + 4) >= *(f32 *)(vars + 8)) {
            func_00474368(moby, 5, -1);
        }
        break;
    case 5:
        break;
    }
}
