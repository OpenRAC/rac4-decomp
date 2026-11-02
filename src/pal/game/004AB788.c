#include "common.h"
typedef struct {
    char p0[12];
    f32 fC;
    char p10[0x160];
} Type1;
extern Type1 D_00308C80[];
extern s32 func_00506BB8(void);
extern s32 func_005064A8(s32, f32);
extern s32 func_005052D0(s32, f32, f32);

/* Applies the active record's scalar to two interface properties. */
void func_004AB788(void)
{
    Type1 *p = &D_00308C80[func_00506BB8()];
    func_005064A8(0x70000, p->fC);
    func_005052D0(0x70000, 0.5f, (1.0f - p->fC) * 0.2f + 0.5f);
}
