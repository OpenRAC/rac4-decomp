#include "common.h"

typedef struct Page {
    u8 pad0[0x10];
    f32 scale;
    u8 pad14[0x8];
    s32 x1C;
    s32 x20;
    u8 pad24[0x234];
} Page;

extern Page D_0030B358[];
extern s32 D_00221960;
extern char D_0030B088[];
extern s32 D_0021F218;
extern char D_0021F9F0[];
extern char D_0021F9F8[];
extern u8 D_001CDB38[];
extern s32 func_00506BB8(void);
extern void func_005026A8(s32 *, s32, s32);
extern void func_00506C08(s32, s32);
extern char *func_0045E850(s32);
extern s32 func_0011D920(char *, const char *, ...);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005062D0(s32, char *);
extern s32 func_005063C0(s32, u32);
extern s32 func_00506000(s32, s32);
extern s32 func_00506590(s32, s32);
extern void func_005052D0(s32, f32, f32);
extern s32 func_005056E0(s32, f32 *, f32 *);
extern s32 func_00506978(s32, f32, f32);
extern s32 func_0049A9D8(void *, s32);
extern s32 func_005071B8(s32, s32);

// Sets up a menu page: title and labels with their colours, four widgets
// scaled by the page scale, and two images.
void func_004BF1A0(void)
{
    s32 ctx = func_00506BB8();
    Page *p = &D_0030B358[ctx];
    f32 x;
    f32 y;
    f32 s;

    func_005026A8(&D_00221960, 0x31, -1);
    func_00506C08(0xF, D_00221960);
    func_005062D0(func_004A2798(&D_00221960, 0x11), D_0030B088);
    if (D_0021F218 == -1) {
        func_0011D920(D_0030B088, D_0021F9F0, func_0045E850(0x2EE9), func_0045E850(0x234F));
    } else {
        func_0011D920(D_0030B088, D_0021F9F8, func_0045E850(0x2EE9), func_0045E850(0x234F), func_0045E850(0x2350));
    }
    func_005063C0(func_004A2798(&D_00221960, 0x11), 0x80808080);
    func_005062D0(func_004A2798(&D_00221960, 0x12), func_0045E850(0x2EF1));
    func_005062D0(func_004A2798(&D_00221960, 0x10), func_0045E850(0x111));
    func_005063C0(func_004A2798(&D_00221960, 0x10), 0x80808080);
    func_00506590(func_004A2798(&D_00221960, 0x9), 1);
    func_00506590(func_004A2798(&D_00221960, 0xB), 1);
    func_00506590(func_004A2798(&D_00221960, 0x1A), 0x754B);
    func_005063C0(func_004A2798(&D_00221960, 0x1A), 0x80808080);
    func_005052D0(func_004A2798(&D_00221960, 0x1B), 0.5f, 0.566f);
    func_005062D0(func_004A2798(&D_00221960, 0x1B), func_0045E850(0x2EEB));
    s = p->scale;
    y = x = 0.0f;
    func_005062D0(func_004A2798(&D_00221960, 0x1C), func_0045E850(0x2EEC));
    func_005062D0(func_004A2798(&D_00221960, 0x20), func_0045E850(0x2EED));
    func_005056E0(func_004A2798(&D_00221960, 0x1C), &x, &y);
    func_00506978(func_004A2798(&D_00221960, 0x1C), s * x, s * y);
    func_005056E0(func_004A2798(&D_00221960, 0x1D), &x, &y);
    func_00506978(func_004A2798(&D_00221960, 0x1D), s * x, s * y);
    func_005056E0(func_004A2798(&D_00221960, 0x20), &x, &y);
    func_00506978(func_004A2798(&D_00221960, 0x20), s * x, s * y);
    func_005056E0(func_004A2798(&D_00221960, 0x21), &x, &y);
    func_00506978(func_004A2798(&D_00221960, 0x21), s * x, s * y);
    func_005062D0(func_004A2798(&D_00221960, 0x28), func_0045E850(0x2EF8));
    func_00506000(func_004A2798(&D_00221960, 0x28), 0);
    p->x1C = func_0049A9D8(D_001CDB38 + 8, -1);
    func_00506590(func_004A2798(&D_00221960, 7), 1);
    func_005071B8(func_004A2798(&D_00221960, 7), p->x1C);
    p->x20 = func_0049A9D8(D_001CDB38, -1);
    func_00506590(func_004A2798(&D_00221960, 6), 1);
    func_005071B8(func_004A2798(&D_00221960, 6), p->x20);
    func_00506000(func_004A2798(&D_00221960, 0x17), 0);
}
