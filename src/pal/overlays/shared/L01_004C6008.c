#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 D_0021E8A4;
extern s32 D_0021E8A8;
extern u8 D_0039F488[];

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
extern s32 func_00472E70(s32, s32);
extern f32 func_00472EB8(f32, f32);

// In state 0: sets up the moby's parameters (vars+0xF0..+0x114, +0x348..+0x37E, +0xE0..+0xE8),
// picks state 1 if vars[0x460] is set, else runs three setup calls and picks state 3; keeps
// vars+0x494 unless it is -1 (then a random 10..30), and stores two random values. Returns 1,
// or 0 outside state 0.
s32 func_L01_004C6008(u8 *moby) {
    u8 *vars;
    s32 n;
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
    func_00489398(moby, 0.006f, 0.006f, 0.040000003f, 0.10000001f, 0.0f, 0.0f, 0.0f);
    func_00489438(moby, 0.010053097f, 0.010053097f, 0.25132743f);
    func_00484EB0(moby, D_0039F488, 0);
    *(s32 *)(vars + 0xF0) |= 0x102;
    *(f32 *)(vars + 0x100) = 0.75f;
    *(f32 *)(vars + 0x104) = 1.25f;
    *(f32 *)(vars + 0x114) = 15.0f;
    func_L01_005BF498(vars + 0x3E0, moby + 0x10, 0x8000, 1.0f, 4.0f);
    func_0047C570(moby, 8);
    n = *(s32 *)(vars + 0x34C) < 2 ? 15 : *(s32 *)(vars + 0x34C);
    vars[0x37E] = 0;
    vars[0x378] = 20;
    vars[0x37A] = 14;
    *(s32 *)(vars + 0x34C) = n;
    *(f32 *)(vars + 0x35C) = 1.0f;
    *(f32 *)(vars + 0x348) = (f32)n;
    func_L01_005B4F98(moby, 2, -1, 2, 1, 0xFFFF, 0xFFFF, -1, -1);
    vars[0x2B1] = 1;
    *(s32 *)(vars + 0xE8) = 4;
    *(f32 *)(vars + 0xE4) = 1.5f;
    vars[0xE0] = 0;
    *(u16 *)(moby + 0x36) |= 0x10;
    if (vars[0x460] != 0) {
        func_00474368(moby, 1, -1);
    } else {
        func_L01_005713D8(moby);
        func_L01_0058CDE8(moby);
        func_L01_005ACCA0(moby);
        func_00474368(moby, 3, -1);
    }
    t = *(f32 *)(vars + 0x494);
    *(u128 *)(vars + 0x4B0) = *(u128 *)(moby + 0x10);
    if (t != -1.0f) {
        r = t;
    } else {
        r = func_00472F10(10.0f, 30.0f);
    }
    *(f32 *)(vars + 0x494) = r;
    *(s32 *)(vars + 0x49C) = func_00472E70(0, 1);
    *(f32 *)(vars + 0x498) = func_00472EB8(1.7f, 2.3f);
    *(s16 *)(moby + 0x74) = 0;
    return 1;
}
