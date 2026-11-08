#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 D_0021DE98;
extern s32 D_0021EC58;
extern u8 D_00397060[];

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
extern f32 func_00472F10(f32, f32);
extern f32 func_00472EB8(f32, f32);

// Same family as func_L01_003D6998. In state 0: sets up the moby's parameters, picks state 11 or 12
// (vars[0x460] set, by vars[0x461]) or 13 after three setup calls, stores two random values and
// scales +0x70 by 1.25 from its class. Returns 1, or 0 outside state 0.
s32 func_L01_0043B070(u8 *moby) {
    u8 *vars;
    s32 n;
    s32 st;
    s32 m1;
    u128 pos;
    f32 big;

    st = moby[0x20];
    if (st != 0) {
        return 0;
    }
    vars = *(u8 **)(moby + 0xAC);
    func_L00_00714A78(moby);
    big = 1.5f;
    func_00484A60(moby);
    func_00489328(moby, 0.7f, 0.1f, 0.8f, big);
    func_00489398(moby, 0.0064000003f, 0.0064000003f, 0.07000001f, 0.11000001f, 0.0f, 0.0f, 0.0f);
    func_00489438(moby, 0.010053097f, 0.010053097f, 0.25132743f);
    func_00484EB0(moby, D_00397060, 0);
    *(f32 *)(vars + 0x104) = 1.25f;
    *(s32 *)(vars + 0xF0) |= 0x302;
    *(f32 *)(vars + 0x100) = 0.75f;
    *(f32 *)(vars + 0x114) = 15.0f;
    func_L01_005BF498(vars + 0x3E0, moby + 0x10, 0x8300, 1.0f, 4.0f);
    *(s16 *)(vars + 0x6C) = 1;
    *(s16 *)(vars + 0x6A) = 1;
    func_0047C570(moby, 0x10);
    n = *(s32 *)(vars + 0x34C);
    if (n <= st) {
        n = 1;
    }
    vars[0x378] = 20;
    vars[0x37A] = 14;
    *(f32 *)(vars + 0x35C) = 0.5f;
    vars[0x37E] = 0;
    *(s32 *)(vars + 0x34C) = n;
    *(f32 *)(vars + 0x348) = (f32)n;
    vars[0x350] = vars[0x350] == 0 ? 1 : vars[0x350];
    m1 = -1;
    func_L01_005B4F98(moby, 0xA, -1, 2, 7, 0xFFFF, 0xFFFF, -1, m1);
    *(f32 *)(vars + 0xE4) = big;
    *(s32 *)(vars + 0xE8) = 4;
    vars[0xE0] = 0;
    *(u16 *)(moby + 0x36) |= 0x10;
    vars[0x2B8] = m1;
    if (vars[0x460] != 0) {
        func_L01_005713D8(moby);
        if (vars[0x461] == 0) {
            func_L01_005ACCA0(moby);
            func_00474368(moby, 0xC, -1);
        } else {
            func_00474368(moby, 0xB, -1);
        }
    } else {
        func_L01_005713D8(moby);
        func_L01_0058CDE8(moby);
        func_L01_005ACCA0(moby);
        func_00474368(moby, 0xD, -1);
    }
    pos = *(u128 *)(moby + 0x10);
    *(u128 *)(vars + 0x4D0) = 0;
    *(s32 *)(vars + 0x4A0) = 0;
    *(s32 *)(vars + 0x4A4) = 0;
    *(s32 *)(vars + 0x4A8) = 0;
    *(u128 *)(vars + 0x4C0) = pos;
    *(f32 *)(vars + 0x494) = func_00472F10(10.0f, 30.0f);
    *(f32 *)(vars + 0x4B4) = func_00472EB8(3.7f, 4.3f);
    *(f32 *)(moby + 0x70) = *(f32 *)(*(u8 **)(moby + 0x24) + 0x24) * 1.25f;
    if ((D_0021DE98 == 1 || D_0021DE98 == 0x15) && D_0021EC58 == 0x14) {
        *(s16 *)(moby + 0x32) = 0x100;
    }
    return 1;
}
