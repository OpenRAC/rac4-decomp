#include "common.h"
typedef struct {
    char p0[0x34];
    f32 f34;
    char p38[128];
} Type1;
extern Type1 D_00308208[];
extern s32 func_00506BB8(void);
extern s32 func_00498E38(s32);
extern s32 func_00498E58(s32);
extern s32 func_0049B418(f32 *, f32);
extern void func_004A9118(void);

/* Interpolates the active record's state and calls its change handler. */
void func_004A8748(void)
{
    s32 state = 0;
    s32 i = func_00506BB8();
    Type1 *p = &D_00308208[i];
    if (!func_00498E38(i) || func_00498E58(i) != 1)
        state = 1;
    if (func_0049B418(&p->f34, (f32)state))
        func_004A9118();
}
