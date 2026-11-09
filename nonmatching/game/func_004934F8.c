/* Not matching yet: BYTES 4/288 (tools/try_func.py func_004934F8 --diff). Not part of the build. */
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

extern f32 func_004725D8(f32 a0, f32 a1);
extern void *func_00490968(s32);
extern u8 *D_00270A18[];


Type1 *func_004934F8(u128 *a0, u128 *a1, s32 a2, s32 a3, f32 f0, f32 f1, f32 f2, s32 a4, s32 a5) {
    u8 *obj = func_00490968(0x40);
    if (obj != 0) {
        Type1Sub *sub;
        f32 r;
        *(u128 *)(obj + 0x10) = *a0;
        sub = (Type1Sub *)(obj + 0x20);
        obj[9] = 0x21;
        obj[3] = a5 ? 0x48 : 0x44;
        obj[1] = 0;
        obj[2] = D_00270A18[0][1];
        *(s32 *)(obj + 4) = a3;
        *(f32 *)(obj + 0xC) = f0 * 210000.0f;
        r = func_004725D8(0.0f, 255.0f);
        *(s16 *)(obj + 0xA) = a2;
        *(s8 *)(obj + 8) = r;
        sub->pos = *a1;
        sub->unk10 = f1;
        sub->unk14 = f2;
        sub->unk18 = a4;
    }
    return (Type1 *)obj;
}
