#include "common.h"

extern s32 D_0021E8A4;
extern s32 D_0021E8A8;
extern u8 D_0039F748[];

extern void func_00484A60(u8 *);
extern void func_00489328(u8 *, f32, f32, f32, f32);
extern void func_00489398(u8 *, f32, f32, f32, f32, f32, f32, f32);
extern void func_00489438(u8 *, f32, f32, f32);
extern void func_00484EB0(u8 *, void *, s32);
extern void func_L01_005B4F98(u8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0056CA60(u8 *);
extern void func_L01_004C99D8(u8 *);
extern void func_L01_004C9A80(u8 *, s32);

typedef struct {
    u8 pad0[0x10];
    f32 x10;
    f32 x14;
    u8 pad18[0x60];
    f32 x78;
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

typedef struct {
    u8 pad0[0x11];
    u8 x11;
} Sub200;

typedef struct {
    u8 pad0[4];
    f32 x4;
    s32 x8;
} Sub3A0;

// Same family as func_L01_004ADDB8: fills the blocks at vars+0x50, +0x200, +0x280, +0x310 and
// +0x3A0, then calls func_L01_004C99D8 when vars[0x408] and vars[0x409] are both set, else
// func_L01_004C9A80(moby, 1).
void func_L01_004C8708(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    Sub50 *s50;
    Sub310 *s310;
    Sub280 *s280;
    Sub200 *s200;
    Sub3A0 *s3A0;

    if (D_0021E8A4 == 0 && D_0021E8A8 == 1) {
        moby[0x64] = 0;
    }
    func_00484A60(moby);
    func_00489328(moby, 1.0f, 0.5f, 2.0f, 6.0f);
    func_00489398(moby, 0.008f, 0.008f, 0.10000001f, 0.14000002f, 0.080000006f, 0.080000006f, 0.22000001f);
    func_00489438(moby, 0.0025132743f, 0.0025132743f, 0.25132743f);
    vars[0x218] = 2;
    s50 = (Sub50 *)(vars + 0x50);
    s50->x10 = 3.0f;
    s50->x14 = 3.0f;
    *(s32 *)(vars + 0x50) |= 0x302;
    s50->x78 = 2.0f;
    func_00484EB0(moby, D_0039F748, 0);
    s310 = (Sub310 *)(vars + 0x310);
    s310->x1C = 0x403;
    s310->x1A = 7;
    s310->x44 = 2.25f;
    s280 = (Sub280 *)(vars + 0x280);
    s280->x2C = 8;
    s280->x30 = 20;
    s280->x32 = 14;
    s280->x14 = 0.2f;
    s280->x36 = 0;
    s280->x3C = 1;
    if (s280->x4 < 2) {
        s280->x4 = 50;
        *(f32 *)(vars + 0x280) = (f32)*(s32 *)(vars + 0x284);
    }
    if (s280->x8[0] < 2) {
        s280->x8[3] = 1;
        s280->x8[0] = 1;
        s280->x8[2] = 1;
        s280->x8[1] = 2;
    }
    s200 = (Sub200 *)(vars + 0x200);
    func_L01_005B4F98(moby, 14, 6, 2, 11, 0xFFFF, 0xFFFF, -1, -1);
    s200->x11 = 1;
    s3A0 = (Sub3A0 *)(vars + 0x3A0);
    s3A0->x4 = 6.25f;
    s3A0->x8 |= 4;
    *(u16 *)(moby + 0x36) |= 0x10;
    func_L01_0056CA60(vars + 0x3E8);
    if (vars[0x408] != 0 && vars[0x409] != 0) {
        func_L01_004C99D8(moby);
    } else {
        func_L01_004C9A80(moby, 1);
    }
}
