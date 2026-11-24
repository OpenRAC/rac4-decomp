#include "common.h"

typedef struct Page {
    u8 pad0[0x10];
    f32 x10;
    u8 pad14[0x118];
    f32 left;
    f32 right;
    f32 top;
    f32 bottom;
    u8 pad13C[0x34];
} Page;

extern Page D_00308C80[];
extern s32 D_00221770;
extern s32 func_00506BB8(void);
extern void func_005027A0(s32 *, s32, f32);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005061B0(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_005058D8(s32, f32, f32, f32, f32);
extern void func_005052D0(s32, f32, f32);
extern f32 func_00475FB0(f32, f32, f32);
extern void func_005064A8(s32, f32);

// Reads a widget's rectangle into the page, nudges its top and bottom
// down a little and places the frame corners and the fade on it.
void func_004AD740(void)
{
    s32 ctx = func_00506BB8();
    f32 zero = 0.0f;
    f32 *left;
    f32 *top;
    f32 *right;
    f32 *bottom;
    s32 h;

    func_005027A0(&D_00221770, -1, D_00308C80[ctx].x10 + D_00308C80[ctx].x10);
    h = func_004A2798(&D_00221770, 1);
    left = &D_00308C80[ctx].left;
    top = &D_00308C80[ctx].top;
    right = &D_00308C80[ctx].right;
    bottom = &D_00308C80[ctx].bottom;
    func_005061B0(h, left, top, right, bottom);
    *top += 0.004464286f;
    *bottom += 0.004464286f;
    func_005058D8(0x70001, *left, *top, *right, *bottom);
    func_005052D0(0x70003, zero, zero);
    func_005052D0(0x70004, *right - *left, zero);
    func_005052D0(0x70005, zero, *bottom - *top);
    func_005052D0(0x70006, *right - *left, *bottom - *top);
    func_005064A8(0x70008, func_00475FB0(0.85f, 0.375f, D_00308C80[ctx].x10));
}
