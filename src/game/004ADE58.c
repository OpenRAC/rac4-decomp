#include "common.h"

typedef struct {
    char pad0[0x8];
    char name1[0x10];
    char name2[0x14];
    s32 v2C;
    s32 v30;
    s32 v34;
    char pad38[0x8];
    f32 v40;
    char pad44[0x4];
    char title[0x8];
} State;

extern State D_003091A0[];
extern s32 D_00221690;
extern void func_004979A8(void *, s32, s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00505040(u32 id, s32 enabled);
extern s32 func_00505238(u32, void *);
extern void func_00505328(s32, s32);
extern s32 func_00505410(u32 id, f32 amount);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_005058E0(u32 id, f32 a, f32 b);
extern s32 func_00505B20(void);
extern s32 func_00505B70(s32 index, s32 handle);

void func_004ADE58(void)
{
    State *p = &D_003091A0[func_00505B20()];

    func_00501638(&D_00221690, 6, -1);
    func_00505B70(5, D_00221690);
    func_00505238(func_004A1A60(&D_00221690, 5), p->title);
    func_00505410(func_004A1A60(&D_00221690, 5), p->v40);
    func_00505328(func_004A1A60(&D_00221690, 5), 0x8020F0F0);
    func_005058E0(func_004A1A60(&D_00221690, 5), 0.9f, 1.19999695f);
    func_00505238(func_004A1A60(&D_00221690, 3), p->name1);
    func_004979A8(p->name1, p->v2C, 0);
    func_00505238(func_004A1A60(&D_00221690, 4), p->name2);
    func_00505410(func_004A1A60(&D_00221690, 4), (f32)p->v34 / 5.0f);
    func_004979A8(p->name2, p->v30, 1);
    func_005054F8(func_004A1A60(&D_00221690, 2), 0x7534);
    func_00505040(func_004A1A60(&D_00221690, 2), 1);
}
