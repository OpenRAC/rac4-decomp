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

typedef struct Info {
    u8 pad0[0x8];
    s32 x8;
    s32 xC;
    u8 pad10[0x10];
    s32 x20;
    s32 x24;
    s32 x28;
    s32 x2C;
} Info;

typedef struct Totals {
    u8 pad0[0xC];
    s32 xC;
    u8 pad10[0x26];
    s16 x36;
} Totals;

typedef struct Colour {
    s32 x0;
    s32 x4;
    s32 x8;
    u32 xC;
    u8 pad10[0x4];
    s32 x14;
    u8 pad18[0x8];
} Colour;

extern Page D_0030B358[];
extern s32 D_00221960;
extern Totals D_00171BC0;
s32 D_0021F9D0 = 1;
extern char D_0030B118[];
extern char D_0030B130[];
extern char D_0030B0B8[];
extern char D_0030B0E8[];
extern char D_0030B148[];
extern char D_0030B178[];
extern char D_0030B1A8[];
extern char D_0030B1D8[];
extern char D_0021FA08[];
extern char D_0021FA10[];
char D_00221940[8] = "";
char D_00221948[8] = "";
extern u8 D_001CDAA8[];
extern s32 func_00506BB8(void);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_00506000(s32, s32);
extern s32 func_005062D0(s32, char *);
extern s32 func_00506590(s32, s32);
extern s32 func_005063C0(s32, u32);
extern void func_00498618(char *, s32, s32);
extern char *func_0045E850(s32);
extern s32 func_0011D920(char *, const char *, ...);
extern s32 func_004C2118(s32);
extern void func_004999D0(Colour *);
extern s32 func_0054C040(s32);
extern Info *func_0054BEE8(s32);
extern s32 func_004FD330(s32);
extern s32 func_004C1BF8(s32);
extern s32 func_004C1AF8(s32);
extern void func_0049AA18(s32);
extern s32 func_0049A9D8(void *, s32);
extern s32 func_005071B8(s32, s32);

static inline s32 slotCount(s32 kind)
{
    return (kind != 15 && kind != 35) ? 15 : 0;
}

// Fills an info panel for entry e (sibling of func_004C1320): when e->x0
// is set, two formatted numbers and up to two coloured counts; otherwise a
// name, a slot count and an optional extra line. Then two images, and
// func_0054C040(e->id) is stored in D_0021F9D0.
void func_004C0A58(Entry *e)
{
    s32 ctx = func_00506BB8();
    Page *p = &D_0030B358[ctx];
    Info *info = func_0054BEE8(func_0054C040(e->id));
    Totals *t;
    s32 n;
    s32 m;
    s32 k;
    Colour c;
    Colour c2;

    if (e->x0) {
        func_00506000(func_004A2798(&D_00221960, 0x18), 1);
        func_00506000(func_004A2798(&D_00221960, 0x24), 0);
        t = &D_00171BC0;
        func_00498618(D_0030B118, t->xC, 0);
        func_00498618(D_0030B130, info->x20, 0);
        func_0011D920(D_0030B0B8, func_0045E850(0x2EF6), D_0030B118);
        func_0011D920(D_0030B0E8, func_0045E850(0x2EF6), D_0030B130);
        func_005062D0(func_004A2798(&D_00221960, 0x1D), D_0030B0B8);
        func_005062D0(func_004A2798(&D_00221960, 0x21), D_0030B0E8);
        n = info->x28;
        if (n > 0) {
            k = func_004C2118(info->x24);
            func_0011D920(D_0030B148, D_0021FA08, k);
            func_0011D920(D_0030B178, D_0021FA08, n);
            func_005062D0(func_004A2798(&D_00221960, 0x1F), D_0030B148);
            func_005062D0(func_004A2798(&D_00221960, 0x23), D_0030B178);
            c.x0 = 0;
            c.x4 = info->x24;
            func_004999D0(&c);
            func_00506590(func_004A2798(&D_00221960, 0x1E), c.x8);
            func_00506590(func_004A2798(&D_00221960, 0x22), c.x8);
            func_005063C0(func_004A2798(&D_00221960, 0x1E), c.xC);
            func_005063C0(func_004A2798(&D_00221960, 0x22), c.xC);
            func_00506000(func_004A2798(&D_00221960, 0x1E), 1);
            func_00506000(func_004A2798(&D_00221960, 0x1F), 1);
            func_00506000(func_004A2798(&D_00221960, 0x22), 1);
            func_00506000(func_004A2798(&D_00221960, 0x23), 1);
        } else if (info->x2C) {
            c.x0 = 5;
            c2.x0 = 5;
            c.x4 = info->x2C;
            c2.x4 = t->x36;
            func_004999D0(&c);
            func_004999D0(&c2);
            func_005062D0(func_004A2798(&D_00221960, 0x23), func_0045E850(c.x14));
            func_005062D0(func_004A2798(&D_00221960, 0x1F), func_0045E850(c2.x14));
            func_00506590(func_004A2798(&D_00221960, 0x22), c.x8);
            func_00506590(func_004A2798(&D_00221960, 0x1E), c2.x8);
            func_005063C0(func_004A2798(&D_00221960, 0x22), c.xC);
            func_005063C0(func_004A2798(&D_00221960, 0x1E), c2.xC);
            func_00506000(func_004A2798(&D_00221960, 0x22), 1);
            func_00506000(func_004A2798(&D_00221960, 0x1E), 1);
            func_00506000(func_004A2798(&D_00221960, 0x23), 1);
            func_00506000(func_004A2798(&D_00221960, 0x1F), 1);
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
        func_005062D0(func_004A2798(&D_00221960, 0x25), func_0045E850(info->x8));
        func_0011D920(D_0030B1A8, func_0045E850(0x2EEA), func_004FD330(e->id), slotCount(e->id));
        func_005062D0(func_004A2798(&D_00221960, 0x27), D_0030B1A8);
        func_00506000(func_004A2798(&D_00221960, 0x27), 1);
        if (e->x1) {
            func_005062D0(func_004A2798(&D_00221960, 0x28), func_0045E850(0x2EF8));
            func_00506000(func_004A2798(&D_00221960, 0x28), 1);
            m = func_004C1BF8(e->id);
            if (m > 0) {
                k = func_004C1AF8(e->id);
                func_0011D920(D_00221940, D_0021FA10, k);
                func_0011D920(D_00221948, D_0021FA10, m);
                func_0011D920(D_0030B1D8, func_0045E850(0x2EF7), D_00221940, D_00221948);
                func_005062D0(func_004A2798(&D_00221960, 0x26), D_0030B1D8);
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
    p->image = func_0049A9D8(D_001CDAA8 + (e->id - 1) % 20 * 8, -1);
    func_005071B8(func_004A2798(&D_00221960, 9), p->image);
    if (p->frame) {
        func_0049AA18(p->frame);
    }
    p->frame = func_0049A9D8(D_001CDAA8 + 0x2A8 + (e->id - 1) % 20 * 8, -1);
    func_005071B8(func_004A2798(&D_00221960, 0xB), p->frame);
    func_005062D0(func_004A2798(&D_00221960, 0x13), func_0045E850(info->xC));
    func_00506000(func_004A2798(&D_00221960, 0xD), 0);
    func_00506000(func_004A2798(&D_00221960, 0xE), 0);
    func_00506000(func_004A2798(&D_00221960, 0xF), 0);
    func_00506000(func_004A2798(&D_00221960, 0x16), 0);
    func_00506000(func_004A2798(&D_00221960, 0x15), 0);
    func_00506000(func_004A2798(&D_00221960, 0x14), 0);
    D_0021F9D0 = func_0054C040(e->id);
}
