#include "common.h"

typedef struct Type1 {
    char _p0[0x4];
    s32 f4;
    s32 f8;
    char _pC[0x4];
    u8 f10;
    u8 f11;
    u8 f12;
    char _p13[0x6];
    u8 f19;
    u8 f1A;
    u8 f1B;
    char _p1C[0x4];
    s32 f20;
    s32 f24;
} Type1;

typedef struct Type3 {
    s32 a;
    s32 b;
} Type3;

typedef struct Type2 {
    char _p0[0xCBB4];
    s32 f4BB4;
    char _p4BB8[0xC];
    s32 f4BC4;
    char _p4BC8[0xD010 - 0xCBC8];
    Type3 e[1];
} Type2;

extern Type1 D_001711A8[];
extern Type2 D_001C2040[];
extern s32 D_0023AB5C[];

extern s32 func_00157F98(void);
extern void func_001634A8(s32 repeat);
extern s32 func_00163840(s32, s32, s32, s32, s32, void (*)(), Type1 *);
extern s32 func_00163928(void);
extern s32 func_00469C40();
extern void func_004FECE8(Type1 *arg0, s32 arg1);
extern void func_004FED60();

void func_004FE9A0(void) {
    Type2 *base;
    s32 off;
    s32 b;

    func_00157F98();
    func_001634A8(0);
    if (func_00163928() != 0) {
        return;
    }
    switch (D_001711A8[0].f24) {
    case 1:
        base = D_001C2040;
        if (base->e[D_001711A8[0].f4].a != 0 && (b = base->e[D_001711A8[0].f4].b) != 0) {
            off = D_001711A8[0].f20 + base->f4BC4 - (b << 11);
            func_001634A8(1);
            func_00163840(0, off, base->e[D_001711A8[0].f4].a + base->f4BB4, base->e[D_001711A8[0].f4].b, 0, func_004FECE8, D_001711A8);
        } else {
            func_004FECE8(D_001711A8, 0);
        }
        break;
    case 2:
        func_00163840(1, D_001711A8[0].f4, 0, 0, 0, func_004FED60, D_001711A8);
        D_001711A8[0].f24 = 4;
        break;
    case 4: {
        Type2 *base4 = D_001C2040;
        s32 *hdr4 = (s32 *)(D_001711A8[0].f20 + base4->f4BC4 - (base4->e[D_001711A8[0].f4].b << 11));
        if (hdr4[0] != 0) {
            func_00469C40((u8 *)hdr4 + hdr4[0] - (base4->e[D_001711A8[0].f4].a << 11), D_0023AB5C[0]);
            D_001711A8[0].f19 = 1;
        } else {
            D_001711A8[0].f19 = 0;
        }
        D_001711A8[0].f24 = 5;
        break;
    }
    case 5: {
        Type2 *base5 = D_001C2040;
        s32 *hdr5 = (s32 *)(D_001711A8[0].f20 + base5->f4BC4 - (base5->e[D_001711A8[0].f4].b << 11));
        if (hdr5[2] != 0) {
            func_00469C40((u8 *)hdr5 + hdr5[2] - (base5->e[D_001711A8[0].f4].a << 11), D_001711A8[0].f20);
            D_001711A8[0].f1A = 1;
        } else {
            D_001711A8[0].f1A = 0;
        }
        D_001711A8[0].f24 = 6;
        break;
    }
    case 6:
        if (D_001711A8[0].f1B != 0) {
            D_001711A8[0].f24 = 7;
        }
        break;
    case 7:
        if (D_001711A8[0].f8 != 0) {
            D_001711A8[0].f10 = 0;
        } else {
            D_001711A8[0].f10 = 1;
        }
        D_001711A8[0].f12 = 0;
        D_001711A8[0].f24 = 0;
        break;
    }
}
