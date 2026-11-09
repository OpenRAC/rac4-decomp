#include "common.h"

typedef struct Type1 {
    u8 _p0[0x18];
    s32 f18;
    u8 _p1C[0x4];
} Type1;

extern s32 func_0011D920(void *dst, void *fmt, ...);
extern void *func_0045E038(s32 id);
extern s32 func_00497848(s32 i);
extern s32 func_00498918(s32 a, s32 b);
extern s32 func_004A1A60(s32 *group, s32 index);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern void func_00501730(s32 *group, s32 a, f32 value);
extern s32 func_00505040(s32 id, s32 enabled);
extern s32 func_00505238(s32 id, void *text);
extern s32 func_00505328(s32 id, s32 value);
extern s32 func_005054F8(s32 id, s32 amount);
extern s32 func_00505B70(s32 index, s32 handle);

s32 D_0021FA28 = -1; /* retail value */
extern s8 D_0021FA78[];
extern Type1 D_003D2618[];
extern s32 D_002218F8;
extern s8 D_0030E598[];

void func_004CB440(void) {
    s32 i;

    func_00501638(&D_002218F8, 0x24, -1);
    func_00505B70(0xF, D_002218F8);
    func_00501730(&D_002218F8, -1, (f32)func_00497848(0));
    func_0011D920(D_0030E598, D_0021FA78, func_0045E038(0x234F), func_0045E038(0x2350));
    func_00505238(func_004A1A60(&D_002218F8, 0x25), D_0030E598);
    if (D_0021FA28 == 1) {
        func_00505238(func_004A1A60(&D_002218F8, 0x26), func_0045E038(0x2398));
    } else {
        func_00505238(func_004A1A60(&D_002218F8, 0x26), func_0045E038(0x2399));
    }
    for (i = 0; i < 4; i++) {
        func_005054F8(func_004A1A60(&D_002218F8, D_003D2618[i].f18), 0x7547);
        func_00505328(func_004A1A60(&D_002218F8, D_003D2618[i].f18), func_00498918(4, 3));
        func_00505040(func_004A1A60(&D_002218F8, D_003D2618[i].f18), 1);
    }
}
