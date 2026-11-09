#include "common.h"

typedef struct Type1 {
    char p[0x10];
    s32 f10;
    char p14[4];
    s16 f18;
    char q[0x1C4 - 0x1A];
    s32 f1C4, f1C8, f1CC, f1D0;
} Type1;

typedef struct Type2 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} Type2;

extern Type1 D_00171948[];
extern Type2 D_003D90F8[];

extern s32 func_0045E038(s32);
extern void func_00466310(void);
extern void func_0049F2F0(s32 arg0, void (*arg1)());
extern void func_0049F660(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
extern void func_004A0040(s32 slot, s32 count, void *items);
extern void func_004A01D8(s32 arg0, s8 arg1);
extern void func_004A01F0(s32 arg0, s32 arg1);
extern void func_004E0858(void);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);
extern void func_004A2328(void *a0);

void func_004A2158(s32 arg0) {
    D_00171948[0].f10 = 0;
    if (D_00171948[0].f1CC < 0) {
        D_00171948[0].f1D0 = 0;
        D_00171948[0].f1CC = 7;
    }
    while (D_00171948[0].f1C4 != 2 || D_00171948[0].f1CC >= 0) {
        func_00466310();
    }
    if (D_00171948[0].f18 >= -1) {
        func_004A01F0(arg0, 1);
    } else {
        func_004A01F0(arg0, 0);
    }
    D_003D90F8[0].f4 = func_0045E038(0x23B5);
    D_003D90F8[0].f10 = func_0045E038(0x144);
    func_0049F660(arg0, 0.685f, 0.28f, 0.37109375f, 0.048076924f);
    func_004A01D8(arg0, 0);
    func_004A0040(arg0, 2, D_003D90F8);
    func_0049F2F0(arg0, func_004A2328);
    func_004E21D8(7, 0, 0);
    func_004E0858();
}
