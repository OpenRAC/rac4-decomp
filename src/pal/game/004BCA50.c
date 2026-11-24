#include "common.h"

typedef struct Page {
    u8 pad0[0x10];
    s32 x10;
    s32 x14;
    u8 pad18[0x51C];
} Page;

typedef struct Colour {
    u8 pad0[0x8];
    s32 x8;
    u32 xC;
} Colour;

extern Page D_0030A6F0[];
extern s32 D_00221920;
extern char D_0030A600[];
extern u8 D_0021F9D9;
extern s32 D_0021DE98;
extern char D_0021F9A0[];
extern char D_0021F9A8[];
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
extern void func_004BD128(void);
extern s32 func_0049A9D8(void *, s32);
extern s32 func_005071B8(s32, s32);

// Sets up a menu page (same layout as func_004C8650): title, labels and
// colours, four coloured icons and two images.
void func_004BCA50(void)
{
    s32 ctx = func_00506BB8();
    Page *p = &D_0030A6F0[ctx];
    Colour *c;

    func_005026A8(&D_00221920, 0x2F, -1);
    func_00506C08(0xF, D_00221920);
    func_005062D0(func_004A2798(&D_00221920, 0x2C), D_0030A600);
    if ((!D_0021F9D9 && D_0021DE98 == 15) || D_0021DE98 == 35) {
        func_0011D920(D_0030A600, D_0021F9A0, func_0045E850(0x234F), func_0045E850(0x2350));
    } else {
        func_0011D920(D_0030A600, D_0021F9A8, func_0045E850(0x2EE9), func_0045E850(0x234F), func_0045E850(0x2350));
    }
    func_005063C0(func_004A2798(&D_00221920, 0x2C), 0x80808080);
    func_005062D0(func_004A2798(&D_00221920, 0x21), func_0045E850(0x3009));
    func_005062D0(func_004A2798(&D_00221920, 0x1F), func_0045E850(0x300A));
    func_005062D0(func_004A2798(&D_00221920, 0x22), func_0045E850(0x300B));
    func_005062D0(func_004A2798(&D_00221920, 0x1D), func_0045E850(0x305A));
    func_005063C0(func_004A2798(&D_00221920, 0x22), 0x80808080);
    func_005063C0(func_004A2798(&D_00221920, 0x1D), 0x80808080);
    func_00506000(func_004A2798(&D_00221920, 0x10), 0);
    func_00506000(func_004A2798(&D_00221920, 0x11), 0);
    func_00506000(func_004A2798(&D_00221920, 0x12), 0);
    func_005062D0(func_004A2798(&D_00221920, 0x2B), func_0045E850(0x300C));
    func_005062D0(func_004A2798(&D_00221920, 0x23), func_0045E850(0x300D));
    func_005062D0(func_004A2798(&D_00221920, 0x27), func_0045E850(0x2F07));
    func_005062D0(func_004A2798(&D_00221920, 0x25), func_0045E850(0x2F08));
    func_005062D0(func_004A2798(&D_00221920, 0x2E), func_0045E850(0x174));
    func_005063C0(func_004A2798(&D_00221920, 0x2B), 0x80808080);
    func_005063C0(func_004A2798(&D_00221920, 0x27), 0x80808080);
    func_005063C0(func_004A2798(&D_00221920, 0x25), 0x80808080);
    func_005063C0(func_004A2798(&D_00221920, 0x23), 0x80808080);
    func_005063C0(func_004A2798(&D_00221920, 0x2E), 0x80808080);
    c = func_004FCFE8(7);
    func_00506590(func_004A2798(&D_00221920, 0x13), c->x8);
    func_005063C0(func_004A2798(&D_00221920, 0x13), c->xC);
    c = func_004FCFE8(8);
    func_00506590(func_004A2798(&D_00221920, 0x14), c->x8);
    func_005063C0(func_004A2798(&D_00221920, 0x14), c->xC);
    c = func_004FCFE8(9);
    func_00506590(func_004A2798(&D_00221920, 0x15), c->x8);
    func_005063C0(func_004A2798(&D_00221920, 0x15), c->xC);
    c = func_004FCFE8(10);
    func_00506590(func_004A2798(&D_00221920, 0x16), c->x8);
    func_005063C0(func_004A2798(&D_00221920, 0x16), c->xC);
    func_00507270(func_004A2798(&D_00221920, 0x30), 1, 1, 1, 0, 0, 0, 0, 0);
    func_005060D8(func_004A2798(&D_00221920, 0x30), 1);
    func_005074A0(func_004A2798(&D_00221920, 0x30), 0xB4, 10, 0.00031f);
    func_004BD128();
    func_00506000(func_004A2798(&D_00221920, 0x30), 0);
    func_00506000(func_004A2798(&D_00221920, 0x28), 0);
    func_00506000(func_004A2798(&D_00221920, 0x20), 0);
    p->x10 = func_0049A9D8(D_001CDB38 + 8, -1);
    func_00506590(func_004A2798(&D_00221920, 0xC), 1);
    func_005071B8(func_004A2798(&D_00221920, 0xC), p->x10);
    p->x14 = func_0049A9D8(D_001CDB38, -1);
    func_00506590(func_004A2798(&D_00221920, 0xD), 1);
    func_005071B8(func_004A2798(&D_00221920, 0xD), p->x14);
    func_005062D0(func_004A2798(&D_00221920, 0x34), func_0045E850(0x350F));
    func_005062D0(func_004A2798(&D_00221920, 0x35), func_0045E850(0x350E));
}
