#include "common.h"

extern void func_0049C248(s32, s32);
extern void func_0049D170(s32 param_a, s32 param_b, s32 source);
extern void func_0049D280(s32, s32);
extern void func_004A1140(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_004A1170(void *arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004DBEC0(void);
extern s32 func_00505B20(void);

extern s32 D_221B88;
extern u8 D_322FC8[];

void func_004DBBC8(void) {
    s32 idx;
    u8 *p;
    u8 *q;

    idx = func_00505B20();
    p = D_322FC8 + idx * 0x168;
    func_004DBEC0();
    q = p + 0xE4;
    *(s32 *)p = 0;
    func_004A1140(q, p + 0xC, 9, 0, 0, 0);
    *(f32 *)(p + 0x160) = 0.024543693f;
    func_0049C248(idx, 0);
    func_0049D170(idx, 0, func_004A1A60(&D_221B88, 0x12));
    func_0049D280(idx, 1);
    func_004A1170(q);
    *(s32 *)(p + 4) = 7;
}
