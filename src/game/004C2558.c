#include "common.h"
typedef struct {
    s32 pad0, pad4;
    s32 flags;
    s32 padC, value;
    char pad14[0x50];
    f32 current;
    char tail[0xC];
} State;
extern State D_0030B7F8[];
extern s32 D_00221888;
extern s32 func_00505B20(void);
extern f32 func_004757E0(f32 *, f32, f32, f32);
extern s32 func_00504238(s32, f32, f32);
void func_004C2558(void)
{
    State *p = D_0030B7F8 + func_00505B20();
    if (func_004757E0(&p->current, (f32)p->value * -0.22596153616905212f, 0.2f, 0.01f) != 0.0f)
        func_00504238(D_00221888, 0.5f, p->current + 0.5f);
    else
        p->flags &= ~8;
}
