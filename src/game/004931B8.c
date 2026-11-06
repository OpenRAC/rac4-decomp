#include "common.h"

typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct Type1Sub {
    u128 pos;
    f32 unk10;
    f32 unk14;
    s32 unk18;
} Type1Sub;

typedef struct Type1 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s8 unk8;
    u8 unk9;
    s16 unkA;
    f32 unkC;
    u128 unk10;
    Type1Sub sub;
} Type1;

extern s32 func_00472560(s32 a0);
extern f32 func_004725D8(f32 a0, f32 a1);
extern void *func_00490968(s32);
extern u8 *D_002709D0[];

Type1 *func_004931B8(u128 *a0, u128 *a1, s32 a2, f32 f0, f32 f1) {
    u8 *obj = func_00490968(0x2E);
    if (obj != 0) {
        Type1Sub *sub;
        *(u128 *)(obj + 0x10) = *a0;
        sub = (Type1Sub *)(obj + 0x20);
        *(s32 *)(obj + 4) = ((func_00472560(0xA) + 0x26) << 24) | 0x808080;
        obj[9] = 0x21;
        obj[3] = 0x48;
        obj[1] = 1;
        obj[2] = *D_002709D0[0];
        *(s16 *)(obj + 0xA) = 5;
        *(f32 *)(obj + 0xC) = f0 * 210000.0f;
        sub->pos = *a1;
        sub->unk10 = func_004725D8(0.0f, 256.0f);
        *(s8 *)(obj + 8) = sub->unk10;
        sub->unk14 = f1;
        sub->unk18 = a2;
    }
    return (Type1 *)obj;
}
