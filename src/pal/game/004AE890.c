#include "common.h"
typedef struct {
    s32 pad;
    f32 value;
    char rest[0x48];
} State;
extern State D_003092A0[];
extern s32 D_00221790;
extern s32 func_00506BB8(void);
extern s32 func_005064A8(s32, f32);
extern s32 func_005052D0(s32, f32, f32);
void func_004AE890(void)
{
    State *p = &D_003092A0[func_00506BB8()];
    func_005064A8(D_00221790, p->value);
    func_005052D0(D_00221790, (1.0f - p->value) * 0.3f + 0.5f, 0.5f);
}
