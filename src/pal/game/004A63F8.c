#include "common.h"

extern s32 func_00506BB8(void);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005064A8(s32, f32);
extern s32 func_005052D0(s32, f32, f32);
extern s32 D_00221728;
typedef struct Type1 {
    char pad[0x4C];
    f32 f4C;
} Type1;
extern Type1 D_00308068[];

/* Apply the selected channel gain and its derived vertical position. */
void func_004A63F8(void)
{
    Type1 *p = D_00308068 + func_00506BB8();
    func_005064A8(func_004A2798(&D_00221728, -1), p->f4C);
    func_005052D0(func_004A2798(&D_00221728, -1), 0.5f,
                  (1.0f - p->f4C) * -0.14423077f + 0.5f);
}
