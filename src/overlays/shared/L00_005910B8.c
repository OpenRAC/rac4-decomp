#include "common.h"

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
} Entry_5910B8;
extern Entry_5910B8 D_0022CA80[];
extern void func_L00_005908F0(u8 *obj);
extern void func_004E1F90(s32, s32, s32);

/* from rac3-decomp's func_L01_003EB158 */
void func_L00_005910B8(u8 *a0) {
    Entry_5910B8 *e = &D_0022CA80[*(s32 *)(a0 + 148)];
    if (e->h2B0 != 0) {
        e->h2B0 = 2;
    } else {
        e->h2B0 = 1;
    }
    e->b2B3 = 0;
    (D_0022CA80 + *(s32 *)(a0 + 148))->f2D8 = 0.075f;
    D_0022CA80[*(s32 *)(a0 + 148)].f2C8 = 0.075f;
    func_L00_005908F0(a0);
    if (e->w124) {
        func_004E1F90(0, 0, e->w124);
    }
}
