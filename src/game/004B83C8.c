#include "common.h"

typedef struct P_004B83C8 {
    u8 pad0[0x2F10];
    s32 unk2F10;
} P_004B83C8;

s32 D_0021F840 = 0;
s32 D_0021F868[2] = { 0 };
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_001711D0[];
extern s32 D_00171D50[][4];
extern s32 D_00171E00[][10];
extern s32 D_00221790;
extern s32 D_003D9390[];
extern s32 func_0045E038(s32);
extern void func_00497980(s32);
extern s32 func_004A1A60(s32 *, s32);
extern void func_00505238(s32, s32);
extern s32 func_00505B20(void);
extern P_004B83C8 *func_00510BE8(s32);

void func_004B83C8(s32 arg0) {
    s32 v;
    s32 idx;
    s32 j;
    s32 *p;
    s32 *q;
    s32 t;
    s32 s;

    v = func_00505B20();
    idx = func_00510BE8((D_0021EDD4 == 0 && D_0021EDD8 == 1) ? D_0021F840 != 1 : v)->unk2F10;
    j = D_001711D0[idx];
    p = &D_00171E00[j][idx];
    q = &D_00171D50[j][idx];
    if (arg0 != 0) {
        t = (*p & 1) ^ 1;
        *q = t;
        *p = t;
        func_00497980(0x10);
    }
    s = func_004A1A60(&D_00221790, D_003D9390[0]);
    func_00505238(s, func_0045E038(D_0021F868[*p]));
}
