#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct {
    f32 unk00;
    f32 unk04;
    s32 unk08;
    f32 unk0C;
    f32 unk10;
    s32 unk14;
} S_467288_Sub;
typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    s32 unk04;
    u8 unk08;
    u8 unk09;
    s16 unk0A;
    f32 unk0C;
    Vec4 unk10;
    S_467288_Sub sub;
} S_467288;
typedef int s128_467510 __attribute__((mode(TI)));
typedef struct {
    s128_467510 q0;
    f32 f10;
    f32 f14;
    int f18;
} P_467510;
extern u8 *D_002709D0[];
extern f32 func_004725D8(f32, f32);
extern S_467288 *func_00490968(s32 size);
extern s32 func_00472560(s32);

/* from rac3-decomp's func_L01_0046ABC0 */
u8 *func_004931B8(s128_467510 *pos, s128_467510 *dir, int life, f32 scale, f32 g) {
    u8 *m = ((u8 * (*)(s32))func_00490968)(46);
    P_467510 *p;
    if (m != 0) {
        *(s128_467510 *)(m + 0x10) = *pos;
        p = (P_467510 *)(m + 0x20);
        *(u32 *)(m + 4) = ((func_00472560(10) + 38) << 24) | 0x808080;
        m[9] = 33;
        m[3] = 72;
        m[1] = 1;
        m[2] = *D_002709D0[0];
        *(s16 *)(m + 10) = 5;
        *(f32 *)(m + 12) = scale * 210000.0f;
        p->q0 = *dir;
        p->f10 = func_004725D8(0.0f, 256.0f);
        m[8] = (int)p->f10;
        p->f14 = g;
        p->f18 = life;
    }
    return m;
}
