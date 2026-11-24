#include "common.h"

typedef struct Page {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    s32 x14;
    s32 x18;
    u8 pad1C[0x48];
} Page;

extern Page D_0030EAA0[];
extern s32 D_00221A20;
extern s32 D_003D27A8[];
extern u8 D_001CDE70[];
extern u8 D_001CDB38[];
extern char D_0021FB38[];
extern s32 func_00506BB8(void);
extern void func_005026A8(s32 *, s32, s32);
extern void func_00506C08(s32, s32);
extern s32 func_004984A0(s32);
extern void func_005027A0(s32 *, s32, f32);
extern s32 func_004A2798(s32 *, s32);
extern char *func_0045E850(s32);
extern s32 func_005062D0(s32, char *);
extern s32 func_00507270(u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_005060D8(s32, s32);
extern s32 func_005074A0(s32, s32, s32, f32);
extern s32 func_00506590(s32, s32);
extern s32 func_0049A9D8(void *, s32);
extern s32 func_005071B8(s32, s32);
extern void func_0049CF80(s32, s32);

// Sets up a save-screen page: title texts, widget states and images.
// When the page field at 0x4 is negative it also sets one more image and
// clears two labels.
void func_004CD2F0(void)
{
    s32 ctx = func_00506BB8();
    Page *p = &D_0030EAA0[ctx];
    s32 i;

    func_005026A8(&D_00221A20, 0x22, -1);
    func_00506C08(0xF, D_00221A20);
    func_005027A0(&D_00221A20, -1, func_004984A0(ctx));
    func_005062D0(func_004A2798(&D_00221A20, 0x24), func_0045E850(0x2350));
    func_005062D0(func_004A2798(&D_00221A20, 0x23), func_0045E850(0x237A));
    func_00507270(func_004A2798(&D_00221A20, 0x26), 1, 1, 1, 0, 0, 0, 0, 0);
    func_005060D8(func_004A2798(&D_00221A20, 0x26), 1);
    func_005074A0(func_004A2798(&D_00221A20, 0x26), 0xB4, 10, 0.00031f);
    for (i = 0; i < 12; i++) {
        func_005060D8(func_004A2798(&D_00221A20, D_003D27A8[i]), 1);
    }
    func_00506590(func_004A2798(&D_00221A20, 0x10), 1);
    p->x10 = func_0049A9D8(D_001CDE70 + 0xB8, -1);
    func_005071B8(func_004A2798(&D_00221A20, 0x10), p->x10);
    func_00506590(func_004A2798(&D_00221A20, 0xF), 1);
    if (p->x4 < 0) {
        p->xC = func_0049A9D8(D_001CDE70, -1);
        func_005071B8(func_004A2798(&D_00221A20, 0xF), p->xC);
        func_0049CF80(ctx, 0);
        func_005062D0(func_004A2798(&D_00221A20, 0x25), D_0021FB38);
        func_005062D0(func_004A2798(&D_00221A20, 0x26), D_0021FB38);
    }
    p->x14 = func_0049A9D8(D_001CDB38 + 8, -1);
    func_00506590(func_004A2798(&D_00221A20, 1), 1);
    func_005071B8(func_004A2798(&D_00221A20, 1), p->x14);
    p->x18 = func_0049A9D8(D_001CDB38, -1);
    func_00506590(func_004A2798(&D_00221A20, 0xE), 1);
    func_005071B8(func_004A2798(&D_00221A20, 0xE), p->x18);
}
