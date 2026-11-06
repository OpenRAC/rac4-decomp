#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 {
    char pad0[0xA8];
    s32 (*fA8)(Type1 *);
    char padAC[0xD8 - 0xAC];
    s32 (*fD8)(Type1 *);
} Type2;
struct Type1 {
    char pad0[0x58];
    Type2 *f58;
};
typedef struct Type3 {
    char pad0[0xB8];
    Type1 *fB8;
    Type1 *fBC;
    Type1 *fC0;
    Type1 *fC4;
    Type1 *fC8;
    Type1 *fCC;
    Type1 *fD0;
    Type1 *fD4;
    Type1 *fD8;
    Type1 *fDC;
    Type1 *fE0;
    Type1 *fE4;
    Type1 *fE8;
    Type1 *fEC;
    Type1 *fF0;
    Type1 *fF4;
    Type1 *fF8;
    Type1 *fFC;
    Type1 *f100;
    Type1 *f104;
    Type1 *f108;
    Type1 *f10C;
    Type1 *f110;
    Type1 *f114;
    Type1 *f118;
    Type1 *f11C;
    Type1 *f120;
    Type1 *f124;
    Type1 *f128;
    Type1 *f12C;
    char pad130[0x2A0 - 0x130];
    u8 f2A0[0x14];
    u8 f2B4[4];
} Type3;

extern void func_0015A1A0(s32);
extern void func_0015AA88(void);
extern void func_001608E0(s32);
extern s32 func_L00_00769D60(void);
extern s32 func_L00_00769D68(s32);
extern s16 func_L00_00769430(s32);
extern s32 *func_L00_00769E58(s32);
#include "pal/profile_001721E0.h"
typedef struct Type5 {
    s8 b[0x3C];
    s32 f3C;
} Type5;
extern Type5 D_00173868;
extern u8 *D_0021E070;

#define GA8(o) ((o)->f58->fA8(o))
#define GD8(o) ((o)->f58->fD8(o))

// PAL version of func_L00_00743DA0: copy the multiplayer menu's option widgets into the
// game settings block. On PAL the four per-player flags at +0x2B4 are filtered in a local
// copy, so the menu's own flags are no longer cleared.
void func_L00_00748860(Type3 *a) {
    s32 mode;
    s32 v;
    s16 level;
    s32 *p;
    s32 i;
    s32 found;
    s32 flags;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    u8 on[4];
    s32 c;
    s32 *t;

    mode = 2;
    if (GA8(a->fB8) == 0) {
        func_001608E0(0);
        mode = 0;
        D_00173868.b[0x29] = GD8(a->fDC);
        D_00173868.b[0x1B] = GD8(a->fE0) / 10;
        D_00173868.b[0x26] = GD8(a->fE4);
        D_00173868.b[0x24] = GD8(a->fE8);
        D_00173868.b[0x2A] = GA8(a->fEC) != 1;
        D_00173868.b[0x16] = GA8(a->fF0) != 0;
        D_00173868.b[0x23] = GA8(a->fF0) == 1;
        D_00173868.b[0xA] = GA8(a->fF0) == 2;
        D_00173868.b[0x18] = 0;
    } else if (GA8(a->fB8) == 1) {
        func_001608E0(3);
        mode = 3;
        D_00173868.b[0x1D] = GD8(a->f110) / 30;
        D_00173868.b[0x2C] = GD8(a->f114);
        D_00173868.b[0x22] = GA8(a->f118);
        D_00173868.b[0x2D] = GA8(a->f11C);
        D_00173868.b[0x2E] = GD8(a->f120);
        D_00173868.b[0x18] = GD8(a->fC0);
    } else if (GA8(a->fB8) == 2) {
        func_001608E0(4);
        D_00173868.b[0x19] = GD8(a->f124);
        D_00173868.b[0x18] = GD8(a->fC0);
        switch (GA8(a->f128)) {
        case 0:
            D_00173868.b[0x34] = 0;
            D_00173868.b[0x35] = 0;
            break;
        case 1:
            D_00173868.b[0x34] = 1;
            D_00173868.b[0x35] = 1;
            break;
        case 2:
            D_00173868.b[0x34] = 1;
            D_00173868.b[0x35] = 0;
            break;
        }
        switch (GA8(a->f12C)) {
        case 0:
            D_00173868.b[0x33] = 0;
            break;
        case 1:
            D_00173868.b[0x33] = 2;
            break;
        case 2:
            D_00173868.b[0x33] = 4;
            break;
        case 3:
            D_00173868.b[0x33] = 6;
            break;
        }
        mode = 4;
    } else if (GA8(a->fB8) == 3) {
        func_001608E0(1);
        mode = 1;
        D_00173868.b[0x1A] = GD8(a->f100);
        D_00173868.b[0x37] = GA8(a->f104) == 0;
        D_00173868.b[0x39] = GA8(a->f108);
        D_00173868.b[0x3A] = GA8(a->f10C);
        D_00173868.b[0x18] = GD8(a->fC0);
    } else if (GA8(a->fB8) == 4) {
        func_001608E0(2);
        v = GA8(a->fF8);
        if (v == 1) {
            D_00173868.b[0x24] = -1;
            D_00173868.b[0x1E] = v;
            D_00173868.b[0x19] = 0;
        } else {
            v = GD8(a->fF4);
            D_00173868.b[0x24] = 6;
            D_00173868.b[0x19] = v;
            D_00173868.b[0x1E] = 0;
        }
        mode = 2;
        D_00173868.b[0x22] = GA8(a->fFC);
        D_00173868.b[0x18] = GD8(a->fC0);
    }

    level = func_L00_00769430(GA8(a->fBC));
    m = GA8(a->fC4);
    if (m == 0) {
        D_00173868.b[0x31] = 0;
    } else if (m == 1) {
        D_00173868.b[0x31] = m;
    } else if (m == 2) {
        D_00173868.b[0x31] = m;
    }
    D_00173868.b[0x2F] = GA8(a->fCC) != 0;
    D_00173868.b[0x30] = GA8(a->fCC) == 2;
    D_00173868.b[0x1F] = GA8(a->fD0) == 1;
    D_00173868.b[0x21] = GA8(a->fD4) != 0;
    D_00173868.b[0x20] = GA8(a->fD8) != 0;

    t = func_L00_00769E58(GA8(a->fBC));
    for (c = 0; c < 4; c++) {
        on[c] = a->f2B4[c];
    }
    p = t;
    for (i = 0; i < 4; i++, p++) {
        if (*p == 0 || GA8(a->fC8) == 0) {
            on[i] = 0;
        }
    }
    found = 0;
    for (j = 0; j < 4; j++) {
        if (on[j] == 1) {
            found = 1;
        }
    }
    D_00173868.b[0xD] = found;
    D_00173868.b[0x2] = on[0];
    D_00173868.b[0x0] = on[1];
    D_00173868.b[0x1] = on[2];
    D_00173868.b[0x3] = on[3];
    D_00173868.b[0x4] = GA8(a->fC8);
    D_00173868.b[0x5] = GA8(a->fC8);
    flags = 0x46002;
    if (GA8(a->fD0) != 2) {
        flags = 0x66002;
    }
    for (k = 0; k < func_L00_00769D60(); k++) {
        n = func_L00_00769D68(k);
        flags |= a->f2A0[n] << n;
    }
    D_00173868.f3C = flags;
    D_001721E0.f258 = 1;
    D_001721E0.f25C = 1;
    D_001721E0.f1C = 1;
    D_001721E0.f228 = 0;
    D_001721E0.f6C9 = 0;
    func_0015A1A0(0);
    func_0015AA88();
    D_001721E0.f260 = 0;
    D_0021E070[0x1A9] = mode;
    *(s16 *)(D_0021E070 + 0x1A4) = level;
}
