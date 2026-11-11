#include "common.h"

extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505238(s32, const char *);
extern const char *func_0045E038(s32);
extern u8 D_0021EE18;
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
s32 D_0021F840 = 0;
extern u8 *D_0021DDCC;
typedef struct { u8 p[0xB4]; u8 fB4[1]; } Type1;
extern Type1 D_00171D38[];
extern s32 D_00221790;
extern s32 D_003D93CC[];
s32 D_0021F878[2] = {
    0x14F1, 0x14F0};

void func_004B8788(s32 arg0)
{
    s32 idx;
    s32 p;
    s32 n;
    u8 *st;

    n = func_00505B20();
    if (D_0021EE18 != 0) {
        st = D_0021DDCC;
    } else {
        st = *(u8 **)((u8 *)func_00510BE8((D_0021EDD4 == 0 && D_0021EDD8 == 1) ? (D_0021F840 != 1) : n) + 0x2F00);
    }
    idx = st[0x54C] * 4 + st[0x558];
    if (arg0) {
        D_00171D38[0].fB4[idx] = !D_00171D38[0].fB4[idx];
        func_00497980(16);
    }
    p = func_004A1A60(&D_00221790, D_003D93CC[0]);
    func_00505238(p, func_0045E038(D_0021F878[D_00171D38[0].fB4[idx]]));
}
