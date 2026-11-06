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

extern State D_00308C80[];
extern const Scale D_003D1A70[];
extern s32 func_00506BB8(void);
extern void func_004AC740(s32);
extern void func_004AD8E8(void);
extern s32 func_00498468(s32);
extern void func_00498560(s32, s32);
extern void func_00497780(void *, s32);

void func_004AAD18(void)
{
    s32 index = func_00506BB8();

    func_004AC740(1);
    func_004AD8E8();
    D_00308C80[index].pending = 0;
    D_00308C80[index].selected = -1;
    D_00308C80[index].value164 = 0;
    D_00308C80[index].value168 = 0;
    D_00308C80[index].value15C = 0;
    D_00308C80[index].value160 = 0;
    D_00308C80[index].scale = D_003D1A70[func_00498468(index)].scale;
    D_00308C80[index].mask = 0x3F;
    func_00498560(index, 0x18);
    func_00497780(&D_00308C80[index], 0);
}
