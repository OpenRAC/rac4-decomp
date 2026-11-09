#include "common.h"

typedef struct {
    char pad[0x2C];
    char name[0x30];
    char s5C[6];
    char s62[0x56];
} Type1;
extern Type1 D_00308108[];
extern s32 D_00221650;
extern char D_0021F6E8[];
extern s32 func_00497810(u32 index);
extern u32 func_004989C0(s32 a0, s32 a1);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00505040(u32 id, s32 enabled);
extern s32 func_00505238(u32, const char *);
extern s32 func_00505328(u32, u32);
extern s32 func_00505410(u32 id, f32 amount);
extern s32 func_005056C8(s32 handle, s32 a, s32 b, s32 c, s32 d);
extern s32 func_00505B20(void);
extern s32 func_00505B70(s32 index, s32 handle);

void func_004A9990(void)
{
    s32 index = func_00505B20();
    Type1 *p = (Type1 *)((u32)index * 0xB8 + (u32)D_00308108);
    s32 a;
    s32 b;
    s32 i;
    s32 j;

    switch (func_00497810(index)) {
    case 0:
    case 1:
    case 2:
    case 3:
        func_00501638(&D_00221650, 0xF, -1);
        break;
    case 4:
        func_00501638(&D_00221650, 0x10, -1);
        break;
    }
    func_00505B70(0xB, D_00221650);
    func_00505238(func_004A1A60(&D_00221650, 0x23), p->name);
    func_00505238(func_004A1A60(&D_00221650, 0x30), p->s5C);
    func_00505238(func_004A1A60(&D_00221650, 0x32), p->s62);
    func_00505238(func_004A1A60(&D_00221650, 0x31), D_0021F6E8);
    a = func_004989C0(index, 0);
    b = func_004989C0(index, 2);
    func_005056C8(func_004A1A60(&D_00221650, 0x2E), b, a, b, a);
    func_00505040(func_004A1A60(&D_00221650, 0x33), 1);
    for (i = 0; i < 9; i++) {
        func_00505040(func_004A1A60(&D_00221650, i + 0xF), 1);
        func_00505410(func_004A1A60(&D_00221650, i + 6), 0.0f);
        func_00505328(func_004A1A60(&D_00221650, i + 6), a);
    }
    for (j = 0; j < 2; j++) {
        func_00505040(func_004A1A60(&D_00221650, j + 0x26), 1);
    }
    func_00505410(func_004A1A60(&D_00221650, 1), 0.0f);
    func_00505410(func_004A1A60(&D_00221650, 0x24), 1.0f);
}
