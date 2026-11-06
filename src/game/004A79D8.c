#include "common.h"
typedef struct {
    char p0[0x34];
    f32 f34;
    char p38[128];
} Type1;
extern Type1 D_00308108[];
extern s32 func_00505B20(void);
extern s32 func_00498100(s32);
extern s32 func_00498120(s32);
extern s32 func_0049A6E0(f32 *, f32);
extern void func_004A83A8(void);

/* Interpolates the active record's state and calls its change handler. */
void func_004A79D8(void)
{
    s32 state = 0;
    s32 i = func_00505B20();
    Type1 *p = &D_00308108[i];
    if (!func_00498100(i) || func_00498120(i) != 1)
        state = 1;
    if (func_0049A6E0(&p->f34, (f32)state))
        func_004A83A8();
}
