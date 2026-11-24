#include "common.h"

typedef struct Page {
    u8 pad0[0xB20];
    s32 xB20;
    u8 padB24[0x4];
    s32 xB28;
    u8 padB2C[0x4];
} Page;

typedef struct Colour {
    u8 pad0[0x8];
    s32 x8;
    u32 xC;
} Colour;

extern Page D_0030B9D8[];
extern s32 D_002219C8;
extern char D_0030B960[];
extern char D_0021FA90[];
extern u8 D_001CDB38[];
extern s32 func_00506BB8(void);
extern void func_005026A8(s32 *, s32, s32);
extern void func_00506C08(s32, s32);
extern char *func_0045E850(s32);
extern s32 func_0011D920(char *, const char *, ...);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005062D0(s32, char *);
extern void func_005063C0(s32, u32);
extern s32 func_00506000(s32, s32);
extern Colour *func_004FCFE8(s32);
extern s32 func_00506590(s32, s32);
extern s32 func_00507270(u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_005060D8(s32, s32);
extern s32 func_005074A0(s32, s32, s32, f32);
extern void func_004C8CB8(void);
extern s32 func_0049A9D8(void *, s32);
extern s32 func_005071B8(s32, s32);

// Sets up a save-screen page: its title, labels, colours and widget states,
// four coloured icons and two images.
void func_004C8650(void)
{
    s32 ctx = func_00506BB8();
    Page *p = &D_0030B9D8[ctx];
    Colour *c;

    func_005026A8(&D_002219C8, 0x2F, -1);
    func_00506C08(0xF, D_002219C8);
    func_0011D920(D_0030B960, D_0021FA90, func_0045E850(0x2EE9), func_0045E850(0x2350), func_0045E850(0x234F));
    func_005062D0(func_004A2798(&D_002219C8, 0x2C), D_0030B960);
    func_005063C0(func_004A2798(&D_002219C8, 0x2C), 0x80D0D0D0);
    func_005062D0(func_004A2798(&D_002219C8, 0x21), func_0045E850(0x3009));
    func_005062D0(func_004A2798(&D_002219C8, 0x1F), func_0045E850(0x300A));
    func_005062D0(func_004A2798(&D_002219C8, 0x22), func_0045E850(0x300B));
    func_005062D0(func_004A2798(&D_002219C8, 0x1D), func_0045E850(0x305A));
    func_005063C0(func_004A2798(&D_002219C8, 0x22), 0x80D0D0D0);
    func_005063C0(func_004A2798(&D_002219C8, 0x1D), 0x80D0D0D0);
    func_00506000(func_004A2798(&D_002219C8, 0x10), 0);
    func_00506000(func_004A2798(&D_002219C8, 0x11), 0);
    func_00506000(func_004A2798(&D_002219C8, 0x12), 0);
    func_005062D0(func_004A2798(&D_002219C8, 0x2B), func_0045E850(0x300C));
    func_005062D0(func_004A2798(&D_002219C8, 0x23), func_0045E850(0x300D));
    func_005062D0(func_004A2798(&D_002219C8, 0x27), func_0045E850(0x2F07));
    func_005062D0(func_004A2798(&D_002219C8, 0x25), func_0045E850(0x2F08));
    func_005062D0(func_004A2798(&D_002219C8, 0x2E), func_0045E850(0x2F18));
    func_005063C0(func_004A2798(&D_002219C8, 0x2B), 0x80D0D0D0);
    func_005063C0(func_004A2798(&D_002219C8, 0x27), 0x80D0D0D0);
    func_005063C0(func_004A2798(&D_002219C8, 0x25), 0x80D0D0D0);
    func_005063C0(func_004A2798(&D_002219C8, 0x23), 0x80D0D0D0);
    func_005063C0(func_004A2798(&D_002219C8, 0x2E), 0x80D0D0D0);
    c = func_004FCFE8(7);
    func_00506590(func_004A2798(&D_002219C8, 0x13), c->x8);
    func_005063C0(func_004A2798(&D_002219C8, 0x13), c->xC);
    c = func_004FCFE8(8);
    func_00506590(func_004A2798(&D_002219C8, 0x14), c->x8);
    func_005063C0(func_004A2798(&D_002219C8, 0x14), c->xC);
    c = func_004FCFE8(9);
    func_00506590(func_004A2798(&D_002219C8, 0x15), c->x8);
    func_005063C0(func_004A2798(&D_002219C8, 0x15), c->xC);
    c = func_004FCFE8(10);
    func_00506590(func_004A2798(&D_002219C8, 0x16), c->x8);
    func_005063C0(func_004A2798(&D_002219C8, 0x16), c->xC);
    func_00507270(func_004A2798(&D_002219C8, 0x30), 1, 1, 1, 0, 0, 0, 0, 0);
    func_005060D8(func_004A2798(&D_002219C8, 0x30), 1);
    func_005074A0(func_004A2798(&D_002219C8, 0x30), 0xB4, 10, 0.00031f);
    func_004C8CB8();
    func_00506000(func_004A2798(&D_002219C8, 0x30), 0);
    func_00506000(func_004A2798(&D_002219C8, 0x28), 0);
    func_00506000(func_004A2798(&D_002219C8, 0x20), 0);
    p->xB20 = func_0049A9D8(D_001CDB38 + 8, -1);
    func_00506590(func_004A2798(&D_002219C8, 0xC), 1);
    func_005071B8(func_004A2798(&D_002219C8, 0xC), p->xB20);
    p->xB28 = func_0049A9D8(D_001CDB38, -1);
    func_00506590(func_004A2798(&D_002219C8, 0xD), 1);
    func_005071B8(func_004A2798(&D_002219C8, 0xD), p->xB28);
    func_005062D0(func_004A2798(&D_002219C8, 0x34), func_0045E850(0x350F));
    func_005062D0(func_004A2798(&D_002219C8, 0x35), func_0045E850(0x350E));
}
