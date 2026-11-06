#include "common.h"

extern s32 func_00505B20(void);
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_00505410(s32, f32);
extern s32 func_00504238(s32, f32, f32);
extern s32 D_00221628;
typedef struct Type1 {
    char pad[0x4C];
    f32 f4C;
} Type1;
extern Type1 D_00307F68[];

/* Apply the selected channel gain and its derived vertical position. */
void func_004A5688(void)
{
    Type1 *p = D_00307F68 + func_00505B20();
    func_00505410(func_004A1A60(&D_00221628, -1), p->f4C);
    func_00504238(func_004A1A60(&D_00221628, -1), 0.5f,
                  (1.0f - p->f4C) * -0.14423077f + 0.5f);
}
