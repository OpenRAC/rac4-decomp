#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 D_0021E8A4;
extern s32 D_0021E8A8;
extern u8 D_00390590[];

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

// In state 0: sets up the moby's parameters (vars+0xE0..+0x114, +0x348..+0x37E), picks state 13 or
// 14 (vars[0x460] set, by vars[0x461]) or 15 after three setup calls, and stores two random
// values at vars+0x494 and +0x498. Returns 1, or 0 outside state 0.
s32 func_L01_003D6998(u8 *moby) {
    u8 *vars;
    s32 n;
    u128 pos;
    f32 big;
    f32 zero;

    if (moby[0x20] != 0) {
        return 0;
    }
    vars = *(u8 **)(moby + 0xAC);
    if (D_0021E8A4 == 0 && D_0021E8A8 == 1) {
        moby[0x64] = 0;
    }
    big = 1.5f;
    func_00484A60(moby);
    zero = 0.0f;
    func_00489328(moby, 0.7f, 0.1f, 0.8f, big);
    func_00489398(moby, 0.040000003f, 0.040000003f, 0.50000006f, 1.0000001f, zero, zero, 1.0000001f);
    func_00489438(moby, 0.010053097f, 0.010053097f, 0.25132743f);
    func_00484EB0(moby, D_00390590, 0);
    *(f32 *)(vars + 0x100) = zero;
    *(f32 *)(vars + 0x104) = zero;
    *(s32 *)(vars + 0xF0) |= 0x20302;
    *(f32 *)(vars + 0x114) = 15.0f;
    func_L01_005BF498(vars + 0x3E0, moby + 0x10, 0x8000, 1.0f, 4.0f);
    *(s16 *)(vars + 0x6C) = 1;
    *(s16 *)(vars + 0x6A) = 1;
    func_0047C570(moby, 0x10);
    n = *(s32 *)(vars + 0x34C);
    if (n <= 0) {
        n = 1;
    }
    vars[0x378] = 20;
    vars[0x37A] = 14;
    *(f32 *)(vars + 0x35C) = 0.2f;
    vars[0x37E] = 0;
    *(s32 *)(vars + 0x34C) = n;
    *(f32 *)(vars + 0x348) = (f32)n;
    vars[0x350] = vars[0x350] == 0 ? 1 : vars[0x350];
    func_L01_005B4F98(moby, 0xC, -1, 5, -1, 0xFFFF, 0xFFFF, 0xB, -1);
    *(f32 *)(vars + 0xE4) = big;
    *(s32 *)(vars + 0xE8) = 4;
    vars[0xE0] = 0;
    *(u16 *)(moby + 0x36) |= 0x10;
    if (vars[0x460] != 0) {
        func_L01_005713D8(moby);
        if (vars[0x461] == 0) {
            func_L01_005ACCA0(moby);
            func_00474368(moby, 0xE, -1);
        } else {
            func_00474368(moby, 0xD, -1);
        }
    } else {
        func_L01_005713D8(moby);
        func_L01_0058CDE8(moby);
        func_L01_005ACCA0(moby);
        func_00474368(moby, 0xF, -1);
    }
    pos = *(u128 *)(moby + 0x10);
    *(u128 *)(vars + 0x4F0) = 0;
    *(s32 *)(vars + 0x4A0) = 0;
    *(s32 *)(vars + 0x4A4) = 0;
    *(s32 *)(vars + 0x4A8) = 0;
    *(u128 *)(vars + 0x4E0) = pos;
    *(f32 *)(vars + 0x494) = func_00472F10(10.0f, 30.0f);
    *(f32 *)(vars + 0x498) = func_00472EB8(3.7f, 4.3f);
    return 1;
}
