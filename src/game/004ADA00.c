#include "common.h"
typedef struct {
    s32 pad;
    f32 value;
    char rest[0x48];
} State;
extern State D_003091A0[];
extern s32 D_00221690;
extern s32 func_00505B20(void);
extern s32 func_00505410(s32, f32);
extern s32 func_00504238(s32, f32, f32);
void func_004ADA00(void)
{
    State *p = &D_003091A0[func_00505B20()];
    func_00505410(D_00221690, p->value);
    func_00504238(D_00221690, (1.0f - p->value) * 0.3f + 0.5f, 0.5f);
}
