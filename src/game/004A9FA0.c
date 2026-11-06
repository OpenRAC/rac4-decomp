#include "common.h"

typedef struct {
    u8 unknown0[0x10];
    s32 pending;
    u8 unknown14[0x12C];
    f32 scale;
    u8 unknown144[8];
    s32 mask;
    u8 unknown150[8];
    s32 selected;
    s32 value15C;
    s32 value160;
    s32 value164;
    s32 value168;
    u8 tail[4];
} State;

typedef struct {
    f32 scale;
    f32 unknown4;
} Scale;

extern State D_00308B80[];
extern const Scale D_003D1A00[];
extern s32 func_00505B20(void);
extern void func_004AB8E8(s32);
extern void func_004ACA68(void);
extern s32 func_00497810(s32);
extern void func_00497908(s32, s32);
extern void func_00496B28(void *, s32);

void func_004A9FA0(void)
{
    s32 index = func_00505B20();

    func_004AB8E8(1);
    func_004ACA68();
    D_00308B80[index].pending = 0;
    D_00308B80[index].selected = -1;
    D_00308B80[index].value164 = 0;
    D_00308B80[index].value168 = 0;
    D_00308B80[index].value15C = 0;
    D_00308B80[index].value160 = 0;
    D_00308B80[index].scale = D_003D1A00[func_00497810(index)].scale;
    D_00308B80[index].mask = 0x3F;
    func_00497908(index, 0x18);
    func_00496B28(&D_00308B80[index], 0);
}
