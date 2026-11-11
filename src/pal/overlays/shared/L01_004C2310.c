#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 D_0039EF08[];

extern s32 func_00472E40(s32);
extern void func_L00_00714A78(u8 *);
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
extern void func_00489290(u8 *, s32);
extern f32 func_00472F10(f32, f32);

// Same family as func_L01_003D6998. In state 0: sets up the moby's parameters, defaults the bytes at
// vars+0x350..0x352 to 10, 2 and 3, and picks state 14, 15, 16 or 17. Returns 1, or 0 outside
// state 0.
s32 func_L01_004C2310(u8 *moby) {
    u8 *vars;
    s32 n;

    if (moby[0x20] != 0) {
        return 0;
    }
    vars = *(u8 **)(moby + 0xAC);
    if (func_00472E40(2)) {
        *(u16 *)(moby + 0x34) |= 0x8000;
    }
    func_L00_00714A78(moby);
    func_00484A60(moby);
    func_00489328(moby, 1.0f, 0.4f, 1.0f, 2.0f);
    func_00489398(moby, 0.006f, 0.006f, 0.040000003f, 0.14000002f, 0.0f, 0.0f, 0.0f);
    func_00489438(moby, 0.010053097f, 0.010053097f, 0.25132743f);
    func_00484EB0(moby, D_0039EF08, 0);
    *(u64 *)(D_0039EF08 + 0x160) |= 8;
    *(u64 *)(D_0039EF08 + 0x160) |= 0x10;
    *(f32 *)(vars + 0x100) = 0.75f;
    *(s32 *)(vars + 0xF0) |= 0x202;
    *(f32 *)(vars + 0x104) = 1.25f;
    *(f32 *)(vars + 0x114) = 15.0f;
    func_L01_005BF498(vars + 0x3E0, moby + 0x10, 0x8300, 1.0f, 4.0f);
    *(s16 *)(vars + 0x6A) = 1;
    *(s16 *)(vars + 0x6C) = 3;
    func_0047C570(moby, 8);
    n = *(s32 *)(vars + 0x34C) < 2 ? 15 : *(s32 *)(vars + 0x34C);
    vars[0x378] = 20;
    vars[0x37A] = 14;
    vars[0x37E] = 0;
    *(f32 *)(vars + 0x35C) = 1.5f;
    *(s32 *)(vars + 0x34C) = n;
    *(f32 *)(vars + 0x348) = (f32)n;
    vars[0x350] = vars[0x350] == 0 ? 10 : vars[0x350];
    vars[0x351] = vars[0x351] == 0 ? 2 : vars[0x351];
    vars[0x352] = vars[0x352] == 0 ? 3 : vars[0x352];
    func_L01_005B4F98(moby, 0xD, -1, 0, 0xC, 0xFFFF, 0xFFFF, -1, -1);
    *(f32 *)(vars + 0xE4) = 1.5f;
    *(s32 *)(vars + 0xE8) = 4;
    vars[0x2B1] = 1;
    vars[0xE0] = 0;
    *(u16 *)(moby + 0x36) |= 0x10;
    *(f32 *)(moby + 0x70) = *(f32 *)(*(u8 **)(moby + 0x24) + 0x24) * 0.85f;
    *(u128 *)(vars + 0x4E0) = *(u128 *)(moby + 0x10);
    *(f32 *)(vars + 0x494) = func_00472F10(10.0f, 30.0f);
    vars[0x4BE] = 1;
    vars[0x2B8] = 0;
    if (vars[0x460] != 0) {
        func_L01_005713D8(moby);
        if (vars[0x4DE] != 0) {
            func_00489290(moby, 0);
            func_00474368(moby, 0x11, -1);
        } else if (vars[0x461] == 0) {
            func_L01_005ACCA0(moby);
            func_00474368(moby, 0xE, -1);
        } else {
            func_00474368(moby, 0xF, -1);
        }
    } else {
        func_L01_005713D8(moby);
        func_L01_0058CDE8(moby);
        func_L01_005ACCA0(moby);
        func_00474368(moby, 0x10, -1);
    }
    return 1;
}
