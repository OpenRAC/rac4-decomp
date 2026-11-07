#include "common.h"

extern u8 D_00399790[];

extern s32 func_00472E40(s32);
extern void func_L00_00714A78(u8 *);
extern void func_00484A60(u8 *);
extern void func_00489328(u8 *, f32, f32, f32, f32);
extern void func_00489398(u8 *, f32, f32, f32, f32, f32, f32, f32);
extern void func_00489438(u8 *, f32, f32, f32);
extern void func_00484EB0(u8 *, void *, s32);
extern void func_L01_005B4F98(u8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_005BF430(u8 *, void *, s32, f32, f32);
extern void func_L01_0056CA60(u8 *);
extern void func_L01_0046A130(u8 *);
extern void func_L01_0046A0A8(u8 *, s32);

typedef struct {
    u8 pad0[0x10];
    f32 x10;
    f32 x14;
} Sub50;

typedef struct {
    u8 pad0[0x1A];
    s16 x1A;
    s16 x1C;
    u8 pad1E[0x26];
    f32 x44;
} Sub310;

typedef struct {
    f32 x0;
    s32 x4;
    u8 x8[4];
    u8 pad0C[8];
    f32 x14;
    u8 pad18[0x14];
    s16 x2C;
    u8 pad2E[2];
    u8 x30;
    u8 pad31;
    u8 x32;
    u8 pad33[3];
    u8 x36;
    u8 pad37[5];
    u8 x3C;
} Sub280;

// Fills the blocks at vars+0x50, +0x280, +0x310 and
// +0x3F0 and its other parameters, then calls func_L01_0046A130 when vars[0x458] and
// vars[0x459] are both set, else func_L01_0046A0A8(moby, 1).
void func_L01_00469BA0(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    Sub50 *s50;
    Sub310 *s310;
    Sub280 *s280;
    u8 *s3F0;
    s32 i;

    if (func_00472E40(2)) {
        *(u16 *)(moby + 0x34) |= 0x8000;
    }
    func_L00_00714A78(moby);
    func_00484A60(moby);
    func_00489328(moby, 1.0f, 1.0f, 2.0f, 6.0f);
    func_00489398(moby, 0.008f, 0.008f, 0.20000002f, 0.20000002f, 0.080000006f, 0.080000006f, 0.22000001f);
    func_00489438(moby, 0.017453294f, 0.017453294f, 0.50265485f);
    s50 = (Sub50 *)(vars + 0x50);
    s50->x10 = 0.5f;
    s50->x14 = 0.5f;
    *(s32 *)(vars + 0x50) |= 0x102;
    func_00484EB0(moby, D_00399790, 0);
    func_L01_005B4F98(moby, 0x1A, 7, 1, -1, 0xFFFF, 0xFFFF, -1, -1);
    s310 = (Sub310 *)(vars + 0x310);
    s310->x1C = 3;
    s310->x1A = 5;
    s310->x44 = 2.25f;
    s280 = (Sub280 *)(vars + 0x280);
    s280->x2C = 8;
    s280->x30 = 20;
    s280->x32 = 14;
    s280->x14 = 1.5f;
    s280->x3C = 1;
    s280->x36 = 0;
    if (s280->x4 < 2) {
        s280->x4 = 20;
        *(f32 *)(vars + 0x280) = (f32)*(s32 *)(vars + 0x284);
    }
    for (i = 0; i < 4; i++) {
        if (s280->x8[i] < 2) {
            s280->x8[i] = 1;
        }
    }
    func_L01_005BF430(moby, moby + 0x10, 0x8300, 1.0f, 4.0f);
    s3F0 = vars + 0x3F0;
    *(f32 *)(s3F0 + 4) = 1.0f;
    *(s32 *)(s3F0 + 8) |= 4;
    *(u16 *)(moby + 0x36) |= 0x10;
    func_L01_0056CA60(vars + 0x438);
    if (vars[0x458] != 0 && vars[0x459] != 0) {
        func_L01_0046A130(moby);
    } else {
        func_L01_0046A0A8(moby, 1);
    }
}
