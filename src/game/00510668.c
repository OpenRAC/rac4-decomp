#include "common.h"

typedef struct {
    u8 pad0[0x16];
    s16 unk16;
} Type1;

typedef struct {
    u8 pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 pad24[0xC];
    u32 unk30;
    u8 pad34[0xC];
    f32 unk40;
    f32 unk44;
    u8 pad48[4];
    Type1 *unk4C;
} Type0;

extern u8 D_00171DEB[];
extern s32 *D_0021DDA4;
extern f32 D_00220AC4;
extern f32 D_00220AC8;
extern f32 D_00220ACC;
extern f32 D_00220AD0;
extern f32 D_00220AE4;
extern f32 D_00220AE8;

f32 func_00453BA0(s32, f32);
void func_004EE248(Type1 *, s32, s32, f32, f32, f32, u32, f32);

void func_00510668(Type0 *arg0, f32 *arg1, f32 arg2) {
    f32 scale;
    f32 x;
    f32 y;
    Type1 *obj;
    u32 color;
    f32 frame;
    s32 idx;
    f32 sx;
    f32 sy;
    f32 t;
    f32 frac;

    if (arg0->unk4C == NULL) {
        return;
    }
    scale = arg0->unk14;
    if (D_00171DEB[0] != 0 && scale == 6.5f && *D_0021DDA4 == 2) {
        scale = 10.136f;
    }
    x = (arg1[2] - arg1[0]) * scale + arg1[0];
    y = (arg1[3] - arg1[1]) * arg0->unk18 + arg1[1];
    color = arg0->unk30;
    if (arg2 < 0.999f) {
        color = (color & 0xFFFFFF) | ((s32)((f32)(color >> 24) * arg2) << 24);
    }
    obj = arg0->unk4C;
    sx = arg0->unk1C;
    sy = arg0->unk20;
    t = arg0->unk40;
    frame = arg0->unk44;
    if (obj != NULL) {
        idx = (s32)frame;
        frac = frame - (f32)idx;
        if (idx < obj->unk16) {
            if (frac >= 0.001f && idx + 1 >= obj->unk16) {
                return;
            }
            func_004EE248(obj, (s32)((x + D_00220ACC) * D_00220AE4), (s32)((y + D_00220AD0) * D_00220AE8),
                          sx * D_00220AC4, sy * D_00220AC8,
                          func_00453BA0(obj->unk16, t), color, frame);
        }
    }
}
