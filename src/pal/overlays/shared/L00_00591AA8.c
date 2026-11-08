#include "common.h"

typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6C58;
typedef int s128_003E8C50 __attribute__((mode(TI)));
typedef struct {
    u8 pad[48];
    s128_003E8C50 q30;
    u8 pad2[112 - 64];
    s32 *f70;
    u8 pad3[10];
    s16 h7E;
    u8 pad4[4];
    s16 h84;
    u8 pad5[14];
    s32 f94;
} Obj_003E8C50;
typedef struct {
    u8 pad0[292];
    s32 w124;
    u8 pad128[688 - 296];
    s16 h2B0;
    u8 b2B2;
    u8 b2B3;
    u8 pad2B4[712 - 692];
    f32 f2C8;
    u8 pad2CC[728 - 716];
    f32 f2D8;
    u8 pad2DC[1136 - 732];
} Entry_3E92A8;
void func_L00_005912E0(Obj_003E8C50 *obj);
extern void func_L00_005912E0(Obj_003E8C50 *obj);
extern void func_004E2EF0(s32, s32, s32);
extern Entry_3E6C58 D_0022CB80[];

/* PAL: from rac3-decomp's func_L01_003EB158 */
void func_L00_00591AA8(u8 *a0) {
    Entry_3E92A8 *e = &((Entry_3E92A8 *)&D_0022CB80)[*(s32 *)(a0 + 148)];
    if (e->h2B0 != 0) {
        e->h2B0 = 2;
    } else {
        e->h2B0 = 1;
    }
    e->b2B3 = 0;
    (((Entry_3E92A8 *)&D_0022CB80) + *(s32 *)(a0 + 148))->f2D8 = 0.075f;
    ((Entry_3E92A8 *)&D_0022CB80)[*(s32 *)(a0 + 148)].f2C8 = 0.075f;
    ((void (*)(u8 *))func_L00_005912E0)(a0);
    if (e->w124) {
        func_004E2EF0(0, 0, e->w124);
    }
}
