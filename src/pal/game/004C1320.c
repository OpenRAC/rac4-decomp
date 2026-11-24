#include "common.h"

typedef struct Entry {
    u8 x0;
    u8 x1;
    u8 pad2[0x2];
    s32 id;
} Entry;

typedef struct Page {
    u8 pad0[0x14];
    s32 image;
    s32 frame;
    u8 pad1C[0x23C];
} Page;

typedef struct Level {
    u8 pad0[0x8];
    s32 name;
} Level;

typedef struct Colour {
    s32 x0;
    s32 x4;
    s32 x8;
    u32 xC;
    u8 pad10[0x10];
} Colour;

extern Page D_0030B358[];
extern s32 D_00221960;
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 D_00171BCC[];
s32 D_0021F9D0 = 1;
extern char D_0030B268[];
extern char D_0030B280[];
extern char D_0030B208[];
extern char D_0030B238[];
extern char D_0030B298[];
extern char D_0030B2C8[];
extern char D_0030B2F8[];
extern char D_0030B328[];
extern char D_0021FA08[];
extern char D_0021FA10[];
char D_00221950[8] = "";
char D_00221958[8] = "";
extern u8 D_001CDAA8[];
extern u8 D_001CE468[];
extern u8 D_001CDD50[];
extern s32 func_00506BB8(void);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_00506000(s32, s32);
extern s32 func_005062D0(s32, char *);
extern s32 func_00506590(s32, s32);
extern s32 func_005063C0(s32, u32);
extern void func_00498618(char *, s32, s32);
extern s32 func_004BFFB0(s32);
extern char *func_0045E850(s32);
extern s32 func_0011D920(char *, const char *, ...);
extern void func_004C0038(s32, s32 *, s32 *);
extern s32 func_004C2118(s32);
extern void func_004999D0(Colour *);
extern s32 func_0054C040(s32);
extern Level *func_0054BEE8(s32);
extern s32 func_004FD330(s32);
extern s32 func_004C1DA0(s32);
extern s32 func_004C1CA8(s32);
extern void func_0049AA18(s32);
extern s32 func_004C00E8(s32);
extern s32 func_0049A9D8(void *, s32);
extern s32 func_005071B8(s32, s32);
extern s32 func_004BFF38(s32);

static inline s32 slotCount(s32 kind)
{
    return (kind != 15 && kind != 35) ? 15 : 0;
}

// Fills an info panel for entry e. When e->x0 is set it shows two
// formatted numbers and an optional pair of counts; otherwise a level name,
// a slot count and an optional extra line. Then it sets two images and
// stores func_0054C040(1) in D_0021F9D0.
void func_004C1320(Entry *e)
{
    s32 ctx = func_00506BB8();
    Page *p = &D_0030B358[ctx];
    s32 kind = 1;
    Colour c;
    s32 a;
    s32 b;
    s32 n;
    s32 m;
    Level *info;

    if (D_0021EE54 == 0 && D_0021EE58 == 1) {
        kind = 21;
    }
    if (e->x0) {
        func_00506000(func_004A2798(&D_00221960, 0x18), 1);
        func_00506000(func_004A2798(&D_00221960, 0x24), 0);
        func_00498618(D_0030B268, D_00171BCC[0], 0);
        func_00498618(D_0030B280, func_004BFFB0(e->id), 0);
        func_0011D920(D_0030B208, func_0045E850(0x2EF6), D_0030B268);
        func_0011D920(D_0030B238, func_0045E850(0x2EF6), D_0030B280);
        func_005062D0(func_004A2798(&D_00221960, 0x1D), D_0030B208);
        func_005062D0(func_004A2798(&D_00221960, 0x21), D_0030B238);
        a = 0;
        b = 0;
        func_004C0038(e->id, &a, &b);
        if (a > 0) {
            n = func_004C2118(b);
            func_0011D920(D_0030B298, D_0021FA08, n);
            func_0011D920(D_0030B2C8, D_0021FA08, a);
            func_005062D0(func_004A2798(&D_00221960, 0x1F), D_0030B298);
            func_005062D0(func_004A2798(&D_00221960, 0x23), D_0030B2C8);
            c.x0 = 0;
            c.x4 = b;
            func_004999D0(&c);
            func_00506590(func_004A2798(&D_00221960, 0x1E), c.x8);
            func_00506590(func_004A2798(&D_00221960, 0x22), c.x8);
            func_005063C0(func_004A2798(&D_00221960, 0x1E), c.xC);
            func_005063C0(func_004A2798(&D_00221960, 0x22), c.xC);
            func_00506000(func_004A2798(&D_00221960, 0x1E), 1);
            func_00506000(func_004A2798(&D_00221960, 0x1F), 1);
            func_00506000(func_004A2798(&D_00221960, 0x22), 1);
            func_00506000(func_004A2798(&D_00221960, 0x23), 1);
        } else {
            func_00506000(func_004A2798(&D_00221960, 0x1E), 0);
            func_00506000(func_004A2798(&D_00221960, 0x1F), 0);
            func_00506000(func_004A2798(&D_00221960, 0x22), 0);
            func_00506000(func_004A2798(&D_00221960, 0x23), 0);
        }
        func_00506000(func_004A2798(&D_00221960, 0x13), 0);
    } else {
        func_00506000(func_004A2798(&D_00221960, 0x18), 0);
        func_00506000(func_004A2798(&D_00221960, 0x24), 1);
        info = func_0054BEE8(func_0054C040(kind));
        func_005062D0(func_004A2798(&D_00221960, 0x25), func_0045E850(info->name));
        if (e->id == 0) {
            func_0011D920(D_0030B2F8, func_0045E850(0x2EEA), func_004FD330(kind), slotCount(kind));
            func_005062D0(func_004A2798(&D_00221960, 0x27), D_0030B2F8);
            func_00506000(func_004A2798(&D_00221960, 0x27), 1);
        } else {
            func_00506000(func_004A2798(&D_00221960, 0x27), 0);
        }
        if (e->x1) {
            func_005062D0(func_004A2798(&D_00221960, 0x28), func_0045E850(0x3480));
            func_00506000(func_004A2798(&D_00221960, 0x28), 1);
            n = func_004C1DA0(e->id);
            if (n > 0) {
                m = func_004C1CA8(e->id);
                func_0011D920(D_00221950, D_0021FA10, m);
                func_0011D920(D_00221958, D_0021FA10, n);
                func_0011D920(D_0030B328, func_0045E850(0x2EF7), D_00221950, D_00221958);
                func_005062D0(func_004A2798(&D_00221960, 0x26), D_0030B328);
                func_00506000(func_004A2798(&D_00221960, 0x26), 1);
            } else {
                func_00506000(func_004A2798(&D_00221960, 0x26), 0);
            }
        } else {
            func_00506000(func_004A2798(&D_00221960, 0x28), 0);
            func_00506000(func_004A2798(&D_00221960, 0x26), 0);
        }
        func_00506000(func_004A2798(&D_00221960, 0x13), 1);
    }
    if (p->image) {
        func_0049AA18(p->image);
    }
    if (e->id == 0) {
        p->image = func_0049A9D8(D_001CDAA8 + e->id % 20 * 8, -1);
    } else {
        p->image = func_0049A9D8(D_001CE468 + func_004C00E8(e->id) * 8, -1);
    }
    func_005071B8(func_004A2798(&D_00221960, 9), p->image);
    if (p->frame) {
        func_0049AA18(p->frame);
    }
    p->frame = func_0049A9D8(D_001CDD50, -1);
    func_005071B8(func_004A2798(&D_00221960, 0xB), p->frame);
    func_005062D0(func_004A2798(&D_00221960, 0x13), func_0045E850(func_004BFF38(e->id)));
    func_00506000(func_004A2798(&D_00221960, 0xD), 0);
    func_00506000(func_004A2798(&D_00221960, 0xE), 0);
    func_00506000(func_004A2798(&D_00221960, 0xF), 0);
    func_00506000(func_004A2798(&D_00221960, 0x16), 0);
    func_00506000(func_004A2798(&D_00221960, 0x15), 0);
    func_00506000(func_004A2798(&D_00221960, 0x14), 0);
    D_0021F9D0 = func_0054C040(1);
}
