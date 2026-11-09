/* cflags: -ffast-math */
#include "common.h"
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} Type1;

typedef struct {
    u8 pad0[0x24];
    Type1 *f24;
    u8 pad28[0x69 - 0x28];
    s8 f69;
    u8 pad6A[0x70 - 0x6A];
    f32 f70;
} Type2;

typedef struct {
    u8 pad0[0x74];
    s32 f74;
    u8 pad78[0x80 - 0x78];
    s16 f80;
    u8 pad82[0x1F0 - 0x82];
    Type2 *f1F0;
} Type3;

typedef struct {
    u8 pad0[0x50];
    u8 f50;
    u8 f51;
} Type4;

extern u32 D_002213F4;
extern u32 D_0022140C;
extern Type3 D_00237000;
extern Type4 D_003289E8;

extern void func_00470870(u32 arg);
extern s32 func_004F4D28(void);

s32 func_004F5B50(s32 arg0)
{
    u32 p;
    s32 ret;
    f32 f;
    Type2 *obj;

    p = D_002213F4;
    ret = 0;
    while (p < D_0022140C) {
        func_00470870(p);
        p += 0x100;
    }
    D_003289E8.f50 = func_004F4D28();
    if (D_003289E8.f50 != 0 && arg0 != 0) {
        ret = D_003289E8.f51 != 0;
    }
    if (D_003289E8.f51 != 0 && D_00237000.f80 - 0x50 < D_00237000.f74) {
        f = (f32)(D_00237000.f80 - D_00237000.f74 - 4) * 0.013157895f;
        f = f < 0.0f ? 0.0f : f;
        obj = D_00237000.f1F0;
        obj->f70 = obj->f24->f24 * f;
        obj->f69 = -0x80 - (s32)(f * 128.0f);
    }
    return ret;
}
