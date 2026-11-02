#include "common.h"
typedef struct {
    char pad[8];
    s32 flags;
    s32 choice;
    char rest[0x64];
} State;
extern State D_0030B7F8[];
extern s32 func_00506BB8(void);
extern void func_004C3DA0(void);
extern void func_004C3E20(void);
extern s32 func_004C3D50(s32);
extern s32 func_00498320(s32 *, s32, s32, void (*)(void), void (*)(void), s32 (*)(s32));
extern void func_004985F0(s32);
extern void func_004C3438(void);
void func_004C3EE0(s32 a)
{
    State *p = &D_0030B7F8[func_00506BB8()];
    if (func_00498320(&p->choice, 10, a, func_004C3DA0, func_004C3E20, func_004C3D50)) {
        func_004985F0(15);
        func_004C3438();
        p->flags |= 1;
    }
}
