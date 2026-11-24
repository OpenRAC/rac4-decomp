#include "common.h"

typedef struct Menu {
    u8 pad0[0x1C];
    char x1C[0x10];
    char x2C[0x8];
    char x34[0x4];
    char x38[8][4];
    u8 pad58[0x1C];
} Menu;

typedef struct Profile {
    u8 pad0[0xBD];
    u8 xBD;
} Profile;

typedef struct Item {
    s32 id;
    u8 pad4[0x8];
} Item;

typedef struct Pair {
    s32 id;
    s32 x4;
} Pair;

typedef struct Count {
    s32 n;
} Count;

extern Menu D_0030B7F8[];
extern s32 D_00221980;
extern s32 D_00221988;
extern Profile D_00171DB8;
extern Count *D_0021DE2C;
extern Item D_003D21F0[];
extern Pair D_003D2268[];
extern Pair D_003D22B8[];
extern s32 D_003D2390[];
extern Pair D_003D2350[];
extern Pair D_003D2308[];
extern s32 D_003D21D8[];
extern s32 func_00506BB8(void);
extern void func_005026A8(s32 *, s32, s32);
extern void func_00506C08(s32, s32);
extern s32 func_004A2798(s32 *, s32);
extern void func_00507C08(s32);
extern s32 func_00506E68();
extern void func_00498818(s32, s32, s32, f32, f32);
extern void func_005075A0(s32, s32, s32);
extern char *func_0045E850(s32);
extern s32 func_005062D0(s32, char *);
extern s32 func_00506978(s32, f32, f32);
extern void func_00431308(s32);
extern s32 func_004996F8(s32, s32);
extern s32 func_005063C0(s32, u32);
extern s32 func_00506590(s32, s32);
extern s32 func_00507270(u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_005060D8(s32, s32);
extern s32 func_005074A0(s32, s32, s32, f32);
extern s32 func_00507758();
extern void func_00507690(s32, s32, s32);
extern s32 func_004C3D08(s32, s32);

// Sets up a menu page with two widget groups: widget scales chosen from
// byte 0xBD of D_00171DB8, labels, one coloured widget per entry counted
// at D_0021DE2C, three widgets set with func_00507270/func_005074A0, and
// the widgets listed in the tables at D_003D21F0..D_003D2390.
void func_004C5650(void)
{
    s32 ctx = func_00506BB8();
    f32 one = 1.0f;
    Menu *m = &D_0030B7F8[ctx];
    Profile *prof;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 h;
    s32 g;
    f32 s;
    f32 rate;

    func_005026A8(&D_00221980, 0x1F, -1);
    func_00506C08(0xF, D_00221980);
    func_00507C08(func_004A2798(&D_00221980, -1));
    g = D_00221980;
    func_00506E68(g, func_004A2798(&D_00221980, -1));
    h = func_004A2798(&D_00221980, 0x4C);
    func_00498818(h, func_004A2798(&D_00221980, -1), 0, one, 0.0f);
    func_005075A0(func_004A2798(&D_00221980, -1), 1, 1);
    func_005026A8(&D_00221988, 0x20, -1);
    func_00506E68(func_004A2798(&D_00221980, -1), D_00221988);
    func_005062D0(func_004A2798(&D_00221980, 0x3C), func_0045E850(0x3050));
    func_005062D0(func_004A2798(&D_00221980, 0x3D), func_0045E850(0x3051));
    func_005062D0(func_004A2798(&D_00221980, 0x3E), func_0045E850(0x3052));
    prof = &D_00171DB8;
    if (prof->xBD == 2) {
        s = 0.87f;
        func_00506978(func_004A2798(&D_00221980, 0x4A), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x48), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x47), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x42), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x4B), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x49), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x46), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x3C), one, one);
        func_00506978(func_004A2798(&D_00221980, 0x3D), one, one);
        func_00506978(func_004A2798(&D_00221980, 0x3E), one, one);
        func_00506978(func_004A2798(&D_00221988, 0x4F), 0.98f, 0.98f);
    }
    if (prof->xBD == 3) {
        s = 0.95f;
        func_00506978(func_004A2798(&D_00221980, 0x4A), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x48), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x47), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x42), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x4B), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x49), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x46), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x3C), one, one);
        func_00506978(func_004A2798(&D_00221980, 0x3D), one, one);
        func_00506978(func_004A2798(&D_00221980, 0x3E), one, one);
    }
    if (prof->xBD == 4) {
        s = 0.95f;
        func_00506978(func_004A2798(&D_00221980, 0x4A), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x48), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x47), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x42), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x4B), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x49), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x46), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x3C), one, one);
        func_00506978(func_004A2798(&D_00221980, 0x3D), one, one);
        func_00506978(func_004A2798(&D_00221980, 0x3E), one, one);
        func_00506978(func_004A2798(&D_00221988, 0x4F), 0.88f, 0.88f);
    }
    if (prof->xBD == 5) {
        s = 0.9f;
        func_00506978(func_004A2798(&D_00221980, 0x4A), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x48), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x47), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x42), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x4B), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x49), s, s);
        func_00506978(func_004A2798(&D_00221980, 0x46), s, s);
        func_00506978(func_004A2798(&D_00221988, 0x4F), 0.85f, 0.85f);
    }
    for (i = 0; i < D_0021DE2C->n; i++) {
        func_00431308(func_004A2798(&D_00221980, i + 0xDC));
        func_00506978(func_004A2798(&D_00221980, i + 0xDC), 0.04f, 0.0533332f);
        func_005063C0(func_004A2798(&D_00221980, i + 0xDC), func_004996F8(i, 0));
        func_00506590(func_004A2798(&D_00221980, i + 0xDC), 0x7581);
        g = D_00221980;
        func_00506E68(g, func_004A2798(&D_00221980, i + 0xDC));
    }
    rate = 0.00031f;
    func_005062D0(func_004A2798(&D_00221988, 0x4F), func_0045E850(0x3053));
    func_005062D0(func_004A2798(&D_00221980, 0x48), func_0045E850(0x239F));
    func_005062D0(func_004A2798(&D_00221980, 0x4A), func_0045E850(0x239E));
    func_005062D0(func_004A2798(&D_00221980, 0x47), func_0045E850(0x3054));
    func_005062D0(func_004A2798(&D_00221980, 0x42), func_0045E850(0x3055));
    func_005062D0(func_004A2798(&D_00221980, 0x40), func_0045E850(0x239C));
    func_005062D0(func_004A2798(&D_00221980, 0x4B), m->x1C);
    func_005062D0(func_004A2798(&D_00221980, 0x49), m->x2C);
    func_005062D0(func_004A2798(&D_00221980, 0x46), m->x34);
    func_00507270(func_004A2798(&D_00221988, 0x53), 1, 1, 1, 0, 0, 0, 0, 0);
    func_005060D8(func_004A2798(&D_00221988, 0x53), 1);
    func_005074A0(func_004A2798(&D_00221988, 0x53), 0xB4, 10, rate);
    func_005062D0(func_004A2798(&D_00221988, 0x51), func_0045E850(0x304F));
    func_00507270(func_004A2798(&D_00221988, 0x51), 1, 1, 1, 0, 0, 0, 0, 0);
    func_005060D8(func_004A2798(&D_00221988, 0x51), 1);
    func_005074A0(func_004A2798(&D_00221988, 0x51), 0xB4, 10, rate);
    func_005062D0(func_004A2798(&D_00221988, 0x50), func_0045E850(0x304E));
    func_00507270(func_004A2798(&D_00221988, 0x50), 1, 1, 1, 0, 0, 1, 0, 0);
    func_00507758(func_004A2798(&D_00221988, 0x50), 0x400, 1);
    func_00507690(func_004A2798(&D_00221988, 0x50), 0, 1);
    func_005060D8(func_004A2798(&D_00221988, 0x50), 1);
    func_005074A0(func_004A2798(&D_00221988, 0x50), 0xB4, 20, 0.001f);
    for (i = 0; i < 10; i++) {
        func_005060D8(func_004A2798(&D_00221980, D_003D21F0[i].id), 1);
        h = func_004A2798(&D_00221980, D_003D21F0[i].id);
        func_005063C0(h, func_004C3D08(i, 0));
    }
    for (j = 9; j >= 0; j--) {
        func_005060D8(func_004A2798(&D_00221980, D_003D2268[9 - j].id), 1);
        func_005060D8(func_004A2798(&D_00221988, D_003D22B8[9 - j].id), 1);
    }
    for (k = 0; k < 8; k++) {
        func_005062D0(func_004A2798(&D_00221988, D_003D2390[k]), m->x38[k]);
        func_005060D8(func_004A2798(&D_00221988, D_003D2350[k].id), 1);
        func_005060D8(func_004A2798(&D_00221988, D_003D2308[k + 1].id), 1);
    }
    for (l = 5; l >= 0; l--) {
        func_005060D8(func_004A2798(&D_00221988, D_003D21D8[5 - l]), 1);
    }
}
