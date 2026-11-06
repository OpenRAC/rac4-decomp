#include "common.h"

extern s32 func_L00_005C9F50(s32);
extern void func_L00_0071ADF0(void *, u32, s32, void *);
extern void func_L00_0071AE38(void *record, u32 param_a, s32 param_b, s32 text_a, s32 param_c, s32 text_b);
extern s32 func_L00_0071AEF0(void *);
extern void func_L00_0071AFE8(void *, void *);
extern char D_004BF548[];

s32 D_002215CC = 0;
u8 D_002215D0 = 0;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    char fC[0x34];
} Type1;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    char fC[0x34];
    s32 f40;
    s32 f44;
    u8 f48;
    char f49[7];
} Type5;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    char fC[0x34];
    s32 f40;
    char f44[0xCC];
} Type2;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    char fC[0x34];
    s32 f40;
    s32 f44;
    void *f48[98];
} Type3;

typedef struct {
    char pad0[0x58];
    void *f58;
    char pad5C[0x230 - 0x5C];
    s32 f230;
    char pad234[0x23C - 0x234];
    s32 f23C;
    s32 f240;
    char pad244[0x24C - 0x244];
    void *f24C;
    char pad250[0x264 - 0x250];
    u8 f264;
    char pad265[0x2E0 - 0x265];
    u8 f2E0;
} Type4;

// Set up the menu: build one header, five two-text items and six text items
// on the stack, collect them in a list of 12 and hand it to func_L00_0071AFE8.
Type4 *func_L00_00753C68(Type4 *arg0) {
    Type5 a;
    Type2 j0;
    Type1 i0;
    Type1 i1;
    Type1 i2;
    Type1 i3;
    Type1 i4;
    Type1 i5;
    Type2 j1;
    Type2 j2;
    Type2 j3;
    Type2 j4;
    Type3 list;
    Type3 *l;
    s32 c = 0x32000014;

    func_L00_0071AEF0(arg0);
    arg0->f58 = D_004BF548;
    arg0->f2E0 = 1;
    arg0->f23C = 0x20;
    arg0->f240 = 0x32000000;
    arg0->f24C = (char *)arg0 + 0x2EC;
    a.f0 = -1; func_L00_0071ADF0(&a, 0xFFFFFFFF, 0, 0);
    a.f0 = 4;
    a.f40 = c;
    a.f44 = -1;
    a.f48 = 0;
    {
        s32 t = arg0->f240 | 0x20;
        s32 s = func_L00_005C9F50(0x12C4);
        j0.f0 = -1; func_L00_0071ADF0(&j0, 0xFFFFFFFF, 0, 0);
        func_L00_0071AE38(&j0, 0xFFFFFFFF, 0, 0, t, s);
    }
    i0.f0 = -1; func_L00_0071ADF0(&i0, 0xE, arg0->f240 | 0x1F, 0); i0.f0 = 0;
    i1.f0 = -1; func_L00_0071ADF0(&i1, 0xD, arg0->f240 | 0x1E, 0); i1.f0 = 0;
    i2.f0 = -1; func_L00_0071ADF0(&i2, 0xC, arg0->f240 | 0x1D, 0); i2.f0 = 0;
    i3.f0 = -1; func_L00_0071ADF0(&i3, 0xB, arg0->f240 | 0x1C, 0); i3.f0 = 0;
    i4.f0 = -1; func_L00_0071ADF0(&i4, 0xA, arg0->f240 | 0x1B, 0); i4.f0 = 0;
    i5.f0 = -1; func_L00_0071ADF0(&i5, 9, arg0->f240 | 0x1A, 0); i5.f0 = 0;
    {
        s32 t = arg0->f240 | 0x19;
        s32 s = func_L00_005C9F50(0x2EE1);
        j1.f0 = -1; func_L00_0071ADF0(&j1, 0xFFFFFFFF, 0, 0);
        func_L00_0071AE38(&j1, 0xFFFFFFFF, 0, 0, t, s);
    }
    {
        s32 t = arg0->f240 | 0x18;
        s32 s = func_L00_005C9F50(0xFD6);
        j2.f0 = -1; func_L00_0071ADF0(&j2, 0xFFFFFFFF, 0, 0);
        func_L00_0071AE38(&j2, 0xFFFFFFFF, 0, 0, t, s);
    }
    {
        s32 t = arg0->f240 | 0x17;
        s32 s = func_L00_005C9F50(0x2ED4);
        j3.f0 = -1; func_L00_0071ADF0(&j3, 0xFFFFFFFF, 0, 0);
        func_L00_0071AE38(&j3, 0xFFFFFFFF, 0, 0, t, s);
    }
    {
        s32 t = arg0->f240 | 0x16;
        s32 s = func_L00_005C9F50(0x23C1);
        j4.f0 = -1; func_L00_0071ADF0(&j4, 0xFFFFFFFF, 0, 0);
        func_L00_0071AE38(&j4, 0xFFFFFFFF, 0, 0, t, s);
    }
    l = &list;
    l->f0 = -1; func_L00_0071ADF0(l, 0xFFFFFFFF, 0, 0);
    l->f40 = -1;
    list.f44 = 0xC;
    list.f48[0] = &a;
    list.f48[1] = &j0;
    list.f48[2] = &i0;
    list.f48[3] = &i1;
    list.f48[4] = &i2;
    list.f48[5] = &i3;
    list.f48[6] = &i4;
    list.f48[7] = &i5;
    list.f48[8] = &j1;
    list.f48[9] = &j2;
    list.f48[10] = &j3;
    list.f48[11] = &j4;
    func_L00_0071AFE8(arg0, l);
    arg0->f264 = 0;
    arg0->f230 = 2;
    if (D_002215D0 != 0) {
        D_002215D0 = 0;
        D_002215CC = 4;
    }
    return arg0;
}

extern s32 func_L00_005F5068(s32, s32, s32, u32, u32);
extern s32 D_00171950[];
extern u32 D_0021DE80;

s32 func_L00_00754DA0(s32 object) {
    s32 result = 3;
    if (D_00171950[0] == 2) {
        func_L00_005F5068(16, 1, 3, 0, 0);
        D_0021DE80 = 6;
        (*(void (**)(s32))(*(u32 *)(object + 0x58) + 0x140))(object);
        result = 3;
    }
    D_002215CC = result;
    return result;
}
