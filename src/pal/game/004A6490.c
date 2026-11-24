#include "common.h"

typedef struct Target {
    u8 pad0[0x2E8];
    f32 x2E8;
    f32 x2EC;
} Target;

typedef struct Player {
    u8 pad0[0x2E20];
    f32 x2E20;
    u8 pad2E24[0xD0];
    Target *target;
    u8 pad2EF8[0x2C];
    f32 x2F24;
} Player;

typedef struct Bar {
    f32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    f32 x10;
    f32 x14;
    u8 pad18[0x8];
    f32 x20;
    u8 pad24[0x4];
    u8 x28;
    u8 pad29[0x1B];
    s32 dirty;
    s32 x48;
    u8 pad4C[0x4];
} Bar;

extern Bar D_00308068[];
extern s32 D_00221728;
extern s32 D_0021EE54;
extern s16 D_00171BD0[];
extern s32 func_00506BB8(void);
extern Player *func_00511CC0(s32);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005061B0(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_005058D8(s32, f32, f32, f32, f32);
extern f32 func_00526DF8(Player *);

// Copies two pairs of values and one more value from the player into this
// context's entry and sets its dirty flag when any of them changed.
void func_004A6490(void)
{
    s32 ctx = func_00506BB8();
    Bar *s = &D_00308068[ctx];
    Player *pl = func_00511CC0(ctx);
    f32 a;
    f32 b;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    u8 on;

    on = pl->target != 0;
    if (s->x28 != on) {
        s->x28 = on;
        s->dirty = 1;
        s->x48 = 0;
    }
    if (s->x28) {
        a = pl->target->x2E8;
        b = pl->target->x2EC;
    } else {
        a = 0.0f;
        b = 1.0f;
    }
    if (s->x4 != s->x0 || s->x0 != a || s->x8 != b) {
        s->x0 = a;
        s->x8 = b;
        s->dirty = 1;
    }
    if (D_0021EE54 == 1) {
        a = pl->x2E20;
        b = pl->x2F24;
    } else {
        a = pl->x2E20;
        b = D_00171BD0[0];
    }
    if (s->x10 != s->xC || s->xC != a || s->x14 != b) {
        if (D_0021EE54 != 1 && s->x14 < 100.0f && 100.0f <= b) {
            func_005061B0(func_004A2798(&D_00221728, 6), &left, &top, &right, &bottom);
            func_005058D8(func_004A2798(&D_00221728, 6), left, top, right - 0.03f, bottom);
        }
        s->xC = a;
        s->x14 = b;
        s->dirty = 1;
    }
    if (D_0021EE54 != 1) {
        a = func_00526DF8(pl);
        if (a != s->x20) {
            s->x20 = a;
            s->dirty = 1;
        }
    }
}
