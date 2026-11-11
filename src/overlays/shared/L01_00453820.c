#include "common.h"

typedef struct V_00453820 {
    u8 pad0[0x170];
    s32 unk170;
    s32 unk174;
    s32 unk178;
    u8 pad17C[0x19C - 0x17C];
    s32 unk19C;
    u8 pad1A0[0x1DC - 0x1A0];
    u8 unk1DC;
} V_00453820;

typedef struct A_00453820 {
    u8 pad0[0xAC];
    V_00453820 *unkAC;
} A_00453820;

extern s32 func_L01_00453750(s32);
extern s32 func_L01_004537F8(s32);
extern s32 func_L01_0056A718(V_00453820 *, s32);

f32 func_L01_00453820(A_00453820 *arg0) {
    V_00453820 *v;
    s32 total;
    s32 good;
    s32 bad;
    s32 n;

    good = 0;
    total = 0;
    v = arg0->unkAC;
    bad = 0;
    if (v == NULL || v->unk19C > 0 || v->unk1DC == 0) {
        return 0.0f;
    }
    if (v->unk174 != 0) {
        good = func_L01_004537F8(v->unk178);
        total = func_L01_004537F8(v->unk174);
        bad = func_L01_0056A718(v, -1);
    }
    if (v->unk170 != -1) {
        n = func_L01_00453750(v->unk170);
        total += n;
        if (v->unk1DC != 0) {
            good += n;
        }
    }
    if (total <= 0) {
        return 1.0f;
    }
    return (2.0f * good - bad) / (2.0f * total);
}
