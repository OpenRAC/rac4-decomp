/* Not matching yet: BYTES 41/744 (tools/try_func.py func_004AEE80 --diff). Not part of the build. */
#include "common.h"
typedef struct { s32 a; s32 b; u8 c; u8 pad[3]; } Entry;
typedef struct { s32 a; s32 b; s32 id; } Slot;
typedef struct {
    u8 pad0[0x14];
    f32 f14;
    f32 f18[4];
    s32 t28[4];
    f32 f38[4];
    s32 t48[4];
    s32 v58;
    f32 f5C;
    s32 v60;
} Hud;
extern Entry D_003D92A0[];
extern Slot D_003D1A78[];
extern s32 D_002216B0;
extern Hud D_003092A0[];
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 func_00498670(f32 *a, s32 b, s32 c, f32 x);
extern u32 func_004989C0(s32 a0, s32 a1);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004AE820(s32);
extern u32 func_004AED30(s32 arg0);
extern void func_00505328(s32, s32);
extern s32 func_005056C8(s32 handle, s32 a, s32 b, s32 c, s32 d);
extern s32 func_00505B20(void);

void func_004AEE80(void)
{
    s32 i;
    s32 r = func_00505B20();
    Hud *h = &D_003092A0[r];
    s32 c;
    s32 c2;

    for (i = 0; i < 4; i++) {
        if (func_004AE820(i)) {
            func_00505328(func_004A1A60(&D_002216B0, D_003D1A78[i].b), 0x40000000);
            continue;
        }
        c = func_004AED30(i);
        if (h->t28[i] != 0) {
            h->t28[i]--;
            c = func_00498670(&h->f18[i], c, func_004989C0(r, 1), 0.2f);
        }
        func_00505328(func_004A1A60(&D_002216B0, D_003D1A78[i].id), c);
        c = 0x40000000;
        if (D_003D92A0[i].a == 1) {
            h->t48[i] = 0;
        } else if (h->t48[i] != 0) {
            h->t48[i]--;
            c = func_00498670(&h->f38[i], 0x40000000, 0x80FFFFFF, 0.05f);
        }
        func_00505328(func_004A1A60(&D_002216B0, D_003D1A78[i].b), c);
    }
    c = func_004989C0(r, 1);
    c2 = func_004989C0(r, 2);
    if (h->f5C >= 1.0f) {
        c = func_00498670(&h->f14, c, func_004989C0(r, 3), 0.04f);
        if ((D_0021EDD4 != 0 || D_0021EDD8 != 1) && D_003D92A0[2].a == 12) {
            func_00505328(func_004A1A60(&D_002216B0, D_003D1A78[2].b), c);
        }
    }
    if (h->v58 == 0) {
        func_005056C8(func_004A1A60(&D_002216B0, 6), c2, c, c2, c);
    } else {
        func_005056C8(func_004A1A60(&D_002216B0, 6), c, c, c2, c2);
    }
}
