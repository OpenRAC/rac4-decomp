#include "common.h"

typedef struct {
    u8 pad0[0x10];
    f32 x10;
    f32 x14;
    u8 pad18[0x30];
    s32 x48;
} Sub50;

typedef struct {
    u8 pad0[0x1A];
    s16 x1A;
    s16 x1C;
    u8 pad1E[0x12];
    s32 x30;
    u8 pad34[0x10];
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
    u8 pad3D[7];
    u8 x44;
    u8 pad45[0x33];
    s32 x78;
} Sub280;

typedef struct {
    u8 pad0[4];
    f32 x4;
    s32 x8;
} Sub3F0;

extern u8 D_0039FA08[];
extern s32 D_00223E48;

extern void func_00484A60(u8 *);
extern void func_00489328(u8 *, f32, f32, f32, f32);
extern void func_00489398(u8 *, f32, f32, f32, f32, f32, f32, f32);
extern void func_00489438(u8 *, f32, f32, f32);
extern void func_00484EB0(u8 *, void *, s32);
extern void func_L01_005B4F98(u8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00595AD0(u8 *, s32);
extern void func_L01_0056CA60(u8 *);
extern void func_L01_004E5570(u8 *);

// Same family as func_L01_00469BA0: fills the moby's blocks at vars+0x50, +0x280, +0x310
// and +0x3F0 and its other parameters (clearing six flags of the word at vars+0x2F8), then
// calls func_L01_004E5570.
void func_L01_004E4CE8(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    Sub50 *s50;
    Sub310 *s310;
    Sub280 *s280;
    Sub3F0 *s3F0;
    s32 i;

    moby[0x30] = 0xFF;
    *(s16 *)(moby + 0x32) = 0xFF;
    s50 = (Sub50 *)(vars + 0x50);
    func_00484A60(moby);
    func_L01_005B4F98(moby, -1, -1, 5, -1, 0xFFFF, 0xFFFF, -1, -1);
    func_00489328(moby, 1.0f, 1.0f, 2.0f, 6.0f);
    func_00489398(moby, 0.008f, 0.008f, 0.10000001f, 0.20000002f, 0.080000006f, 0.080000006f, 0.22000001f);
    func_00489438(moby, 0.00572468f, 0.00572468f, 0.28623402f);
    s50->x10 = 0.5f;
    s50->x14 = 0.5f;
    *(s32 *)(vars + 0x50) |= 0x103;
    func_00484EB0(moby, D_0039FA08, 0);
    s310 = (Sub310 *)(vars + 0x310);
    s310->x44 = 2.25f;
    s310->x1C = 3;
    s310->x1A = 1;
    s310->x30 = *(s32 *)(vars + 0x490);
    s280 = (Sub280 *)(vars + 0x280);
    s280->x78 &= ~0x100;
    s280->x78 &= ~0x400;
    s280->x78 &= ~0x20;
    s280->x78 &= ~0x800000;
    s280->x78 &= ~0x8000;
    s280->x2C = 8;
    s280->x30 = 20;
    s280->x32 = 14;
    s280->x14 = 4.0f;
    s280->x78 &= ~0x2000000;
    s280->x36 = 0;
    s280->x3C = 1;
    s280->x44 = 1;
    s50->x48 = -1;
    if (s280->x4 < 2) {
        s280->x4 = 200;
        *(f32 *)(vars + 0x280) = (f32)*(s32 *)(vars + 0x284);
    }
    for (i = 0; i < 4; i++) {
        if (s280->x8[i] < 2) {
            s280->x8[i] = 10;
        }
    }
    func_L01_00595AD0(moby, D_00223E48);
    s3F0 = (Sub3F0 *)(vars + 0x3F0);
    s3F0->x4 = 1.0f;
    s3F0->x8 |= 4;
    *(u16 *)(moby + 0x36) |= 0x10;
    *(s32 *)(vars + 0x54C) = 0;
    *(s32 *)(vars + 0x544) = 0x8CA;
    func_L01_0056CA60(vars + 0x438);
    func_L01_004E5570(moby);
}
