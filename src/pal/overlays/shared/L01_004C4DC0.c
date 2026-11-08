#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 D_0021E8A4;
extern s32 D_0021E8A8;
extern u8 D_0039F1C8[];

extern void func_00484A60(u8 *);
extern void func_00489328(u8 *, f32, f32, f32, f32);
extern void func_00489398(u8 *, f32, f32, f32, f32, f32, f32, f32);
extern void func_00489438(u8 *, f32, f32, f32);
extern void func_00484EB0(u8 *, void *, s32);
extern void func_L01_005BF498(u8 *, u8 *, s32, f32, f32);
extern void func_0047C570(u8 *, s32);
extern void func_L01_005B4F98(u8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00474368(u8 *, s32, s32);
extern void func_L01_005713D8(u8 *);
extern void func_L01_0058CDE8(u8 *);
extern void func_L01_005ACCA0(u8 *);
extern f32 func_00472F10(f32, f32);
extern f32 func_00472EB8(f32, f32);
extern s32 func_00472E70(s32, s32);

// Same family as func_L01_003D6998. In state 0: sets up the moby's parameters, picks state 9, 10 or
// 11, keeps vars+0x494 unless it is -1 (then a random 10..30), builds a random bit mask at vars+0x49C
// and ORs it into the moby's +0x74. Returns 1, or 0 outside state 0.
s32 func_L01_004C4DC0(u8 *moby) {
    u8 *vars;
    s32 n;
    s32 a;
    s32 x;
    f32 t;
    f32 r;

    if (moby[0x20] != 0) {
        return 0;
    }
    vars = *(u8 **)(moby + 0xAC);
    if (D_0021E8A4 == 0 && D_0021E8A8 == 1) {
        moby[0x64] = 0;
    }
    func_00484A60(moby);
    func_00489328(moby, 1.0f, 0.4f, 1.0f, 2.0f);
    func_00489398(moby, 0.006f, 0.006f, 0.020000001f, 0.060000002f, 0.0f, 0.0f, 0.0f);
    func_00489438(moby, 0.010053097f, 0.010053097f, 0.25132743f);
    func_00484EB0(moby, D_0039F1C8, 0);
    *(f32 *)(vars + 0x104) = 1.25f;
    *(s32 *)(vars + 0xF0) |= 0x102;
    *(f32 *)(vars + 0x100) = 0.75f;
    *(f32 *)(vars + 0x114) = 15.0f;
    func_L01_005BF498(vars + 0x3E0, moby + 0x10, 0x8000, 1.0f, 4.0f);
    *(s16 *)(vars + 0x6A) = 1;
    *(s16 *)(vars + 0x6C) = 3;
    func_0047C570(moby, 8);
    n = *(s32 *)(vars + 0x34C) < 2 ? 7 : *(s32 *)(vars + 0x34C);
    vars[0x378] = 20;
    vars[0x37A] = 14;
    vars[0x37E] = 0;
    *(f32 *)(vars + 0x35C) = 0.3f;
    *(s32 *)(vars + 0x34C) = n;
    *(f32 *)(vars + 0x348) = (f32)n;
    vars[0x350] = vars[0x350] == 0 ? 10 : vars[0x350];
    vars[0x351] = vars[0x351] == 0 ? 3 : vars[0x351];
    func_L01_005B4F98(moby, 8, -1, 2, 4, 0xFFFF, 0xFFFF, -1, -1);
    vars[0x2B1] = 1;
    *(f32 *)(vars + 0x2C4) = 1.0f;
    *(s32 *)(vars + 0xE8) = 4;
    *(f32 *)(vars + 0xE4) = 1.5f;
    vars[0xE0] = 0;
    *(u16 *)(moby + 0x36) |= 0x10;
    if (vars[0x460] != 0) {
        func_L01_005713D8(moby);
        if (vars[0x461] == 0) {
            func_L01_005ACCA0(moby);
            func_00474368(moby, 9, -1);
        } else {
            func_00474368(moby, 0xA, -1);
        }
    } else {
        func_L01_005713D8(moby);
        func_L01_0058CDE8(moby);
        func_L01_005ACCA0(moby);
        func_00474368(moby, 0xB, -1);
    }
    t = *(f32 *)(vars + 0x494);
    *(u128 *)(vars + 0x4C0) = *(u128 *)(moby + 0x10);
    if (t != -1.0f) {
        r = t;
    } else {
        r = func_00472F10(10.0f, 30.0f);
    }
    *(f32 *)(vars + 0x494) = r;
    vars[0x4BC] = 1;
    *(f32 *)(vars + 0x498) = func_00472EB8(0.7f, 1.3f);
    a = func_00472E70(0, 4);
    *(s32 *)(vars + 0x49C) = (1 << a) | (1 << (func_00472E70(0, 3) + 16));
    if (func_00472EB8(0.0f, 1.0f) < 0.1f) {
        *(s32 *)(vars + 0x49C) = *(s16 *)(vars + 0x49E) << 16;
    }
    x = *(s16 *)(vars + 0x49C) | (*(s16 *)(vars + 0x49E) << 5);
    *(u16 *)(moby + 0x74) |= x;
    return 1;
}
