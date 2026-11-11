#include "common.h"

extern void func_00126E20(s32);
extern s32 func_001595F8(u32 word0, u32 word1, u32 word2, u32 word3, u32 word4);
extern void func_004494E8(s32, s32);
extern void func_00453608(void *p, s32 v, s32 n);
extern void func_0045DE88(void);
extern void func_004E4C50(s32 wait);
extern s32 D_00171FC8[];
extern u8 D_001D2200[];
extern s16 D_00206990[];
extern s32 D_00221E00;
extern s32 D_00221E04;
extern s32 D_00221E08;
extern s32 D_00221E0C;
extern s32 D_00221E10;
extern s32 D_00221E14;

void func_004E4EB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_001D2200[0x43] |= 8;
    func_001595F8(2, 0, 0, 0, 0);
    func_00126E20(0);
    D_00221E00 = arg0;
    D_00221E04 = arg1;
    D_00221E08 = arg2;
    D_00221E0C = arg3;
    D_00221E10 = arg4;
    func_004494E8(4, 1);
    D_00221E14 = D_00206990[0];
    func_004E4C50(1);
    func_00453608(D_00171FC8, 0x400, 0x18);
    func_0045DE88();
}
