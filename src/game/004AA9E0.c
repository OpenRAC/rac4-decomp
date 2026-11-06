#include "common.h"
typedef struct {
    char p0[12];
    f32 fC;
    char p10[0x160];
} Type1;
extern Type1 D_00308B80[];
extern s32 func_00505B20(void);
extern s32 func_00505410(s32, f32);
extern s32 func_00504238(s32, f32, f32);

/* Applies the active record's scalar to two interface properties. */
void func_004AA9E0(void)
{
    Type1 *p = &D_00308B80[func_00505B20()];
    func_00505410(0x70000, p->fC);
    func_00504238(0x70000, 0.5f, (1.0f - p->fC) * 0.2f + 0.5f);
}
