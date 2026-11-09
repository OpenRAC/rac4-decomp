#include "common.h"

typedef struct {
    u8 pad0[0x69];
    u8 f69;
} Type2;

typedef struct {
    u8 pad0[0x74];
    s32 f74;
    u8 pad78[0x80 - 0x78];
    s16 f80;
    u8 pad82[0x1F0 - 0x82];
    Type2 *f1F0;
} Type3;

typedef struct {
    u8 pad0[0x50];
    u8 f50;
    u8 f51;
} Type4;

typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[5];
    u8 f7;
    u8 pad8[0x38];
} Type5;

extern Type3 D_00237000;
extern Type4 D_003289E8;
extern s32 D_003DBFC0[];
extern u32 D_002214E0;
extern s32 D_002214E8;

extern void func_004F3538(void);
extern s32 func_004F4E88(void);
extern void func_004F4FB0(s32 a0);
extern s32 func_004F5000(void);
extern void func_004F5008(void);
extern void func_004F5028(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_004F5350(void);
extern void func_004F5530(void *a0);
extern void func_004F5868(void);
extern void func_004F5AA8(void);

void func_004F5C80(s32 arg0)
{
    s32 v;
    s32 scale;
    u32 p;
    u32 base;
    u32 end;

    if (D_003289E8.f50 != 0) {
        func_004F3538();
        if (func_004F5000() == 1) {
            func_004F5350();
        }
        if (D_003289E8.f51 == 0) {
            if (func_004F5000() > 0 && arg0 != 0) {
                D_003289E8.f51 = 1;
                v = D_003DBFC0[0];
            } else {
                v = func_004F4E88();
            }
            func_004F4FB0(v);
            func_004F5530(func_004F5AA8);
            func_004F5008();
            func_004F5868();
        }
    }
    if (D_003289E8.f51 != 0) {
        func_004F5028(D_00237000.f74, D_00237000.f80 + 1, 15, 0);
    } else {
        func_004F5028(D_00237000.f74, D_00237000.f80, 15, 15);
    }
    if (D_003289E8.f51 != 0) {
        scale = 0;
        if (D_00237000.f1F0 != NULL) {
            scale = 0x80 - D_00237000.f1F0->f69;
        }
        base = D_002214E0;
        end = base + (D_002214E8 << 6) + 0x40;
        for (p = base; p < end; p += 0x40) {
            if (!(((u8 *)p)[1] & 0x80)) {
                ((u8 *)p)[7] = (((u8 *)p)[7] * scale) >> 7;
            }
        }
    }
}
