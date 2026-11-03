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
extern s32 D_00221988;
extern s32 func_00506BB8(void);
extern f32 func_004760C0(f32 *, f32, f32, f32);
extern s32 func_005052D0(s32, f32, f32);
void func_004C3380(void)
{
    State *p = D_0030B7F8 + func_00506BB8();
    if (func_004760C0(&p->current, (f32)p->value * -0.22596153616905212f, 0.2f, 0.01f) != 0.0f)
        func_005052D0(D_00221988, 0.5f, p->current + 0.5f);
    else
        p->flags &= ~8;
}
