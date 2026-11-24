#include "common.h"

typedef struct Counter {
    u8 pad0[0x5C];
    char text[0x6];
    char digits[0x16];
    s32 x78;
    u8 pad7C[0x14];
    f32 offset;
    s32 length;
    u8 pad98[0x20];
} Counter;

extern Counter D_00308208[];
extern s32 D_00221750;
extern char D_0021F770[];
extern char D_0021F778[];
extern f32 D_00220B5C;
extern f32 D_00220B7C;
extern s32 func_0011D920(char *, const char *, ...);
extern s32 func_0011AB04(char *);
extern void func_004A9718(s32, s32);
extern void func_00454B68(s32);
extern s32 func_004A2798(s32 *, s32);
extern void func_005056E0(s32, f32 *, f32 *);
extern s32 func_00457A90(char *, s32, f32);
extern s32 func_005055E8(s32, f32 *, f32 *);
extern void func_005052D0(s32, f32, f32);

// Writes a number into counter i and, when its length changed, measures
// the text and moves the two widgets that follow it.
void func_004A94E8(s32 i, s32 n)
{
    Counter *c = &D_00308208[i];
    s32 old = c->length;
    f32 x;
    f32 y;
    f32 z;
    f32 w;

    if (n == 0) {
        func_0011D920(c->digits, D_0021F770);
        func_0011D920(c->text, D_0021F770);
        c->length = 0;
    } else {
        func_0011D920(c->digits, D_0021F778, n);
        c->length = func_0011AB04(c->digits);
    }
    if (c->length != old) {
        func_004A9718(i, 0);
        c->x78 = 0;
        func_00454B68(0);
        func_005056E0(func_004A2798(&D_00221750, 0x30), &x, &y);
        /* Retail tests the address of c->text as well, so the original
           probably called a helper that takes a string pointer. */
        if (c->text && x != 0.0f) {
            w = func_00457A90(c->text, -1, x * D_00220B5C) / D_00220B7C;
        } else {
            w = 0.0f;
        }
        c->offset = w;
        if (1.0f < w) {
            c->offset = w * 0.001953125f;
        }
        func_005055E8(func_004A2798(&D_00221750, 0x30), &x, &z);
        func_005055E8(func_004A2798(&D_00221750, 0x31), &z, &y);
        func_005052D0(func_004A2798(&D_00221750, 0x31), x + c->offset, y);
        func_005055E8(func_004A2798(&D_00221750, 0x32), &z, &y);
        func_005052D0(func_004A2798(&D_00221750, 0x32), x + c->offset + 0.025f, y);
    }
}
