/* Not matching yet: BYTES 6/552 (tools/try_func.py func_004A8778 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    char pad[0x5C];
    char name[6];
    char text[0x2E];
    f32 f90;
    s32 state;
    char tail[0x20];
} Type1;

extern s32 func_0011AB04(char *);
extern s32 func_0011D920(char *arg0, char *arg1, ...);
extern void func_00454350(s32);
extern s32 func_00457278(char *, s32, f32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004A89A0(s32 arg0, s32 arg1);
extern void func_00504238(s32 handle, f32 a, f32 b);
extern void func_00504550(s32, f32 *, f32 *);
extern void func_00504648(s32, f32 *, f32 *);
extern char D_0021F6D0[];
extern char D_0021F6D8[];
extern f32 D_00220AC4;
extern f32 D_00220AE4;
extern s32 D_00221650;
extern Type1 D_00308108[];

void func_004A8778(s32 index, s32 value)
{
    Type1 *p = &D_00308108[index];
    s32 old = p->state;
    f32 x;
    f32 y;
    f32 z;
    f32 amount;

    if (value == 0) {
        func_0011D920(p->text, D_0021F6D0);
        func_0011D920(p->name, D_0021F6D0);
        p->state = 0;
    } else {
        func_0011D920(p->text, D_0021F6D8, value);
        p->state = func_0011AB04(p->text);
    }
    if (p->state != old) {
        func_004A89A0(index, 0);
        func_00454350(0);
        func_00504648(func_004A1A60(&D_00221650, 0x30), &x, &y);
        if (p->name != 0 && x != 0.0f) {
            amount = (f32)func_00457278(p->name, -1, x * D_00220AC4) / D_00220AE4;
        } else {
            amount = 0.0f;
        }
        p->f90 = amount;
        if (amount > 1.0f) {
            p->f90 = amount * 0.001953125f;
        }
        func_00504550(func_004A1A60(&D_00221650, 0x30), &x, &z);
        func_00504550(func_004A1A60(&D_00221650, 0x31), &z, &y);
        func_00504238(func_004A1A60(&D_00221650, 0x31), x + p->f90, y);
        func_00504550(func_004A1A60(&D_00221650, 0x32), &z, &y);
        func_00504238(func_004A1A60(&D_00221650, 0x32), x + p->f90 + 0.025f, y);
    }
}
