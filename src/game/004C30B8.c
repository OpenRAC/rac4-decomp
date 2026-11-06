#include "common.h"
typedef struct {
    char pad[8];
    s32 flags;
    s32 choice;
    char rest[0x64];
} State;
extern State D_0030B7F8[];
extern s32 func_00505B20(void);
extern void func_004C2F78(void);
extern void func_004C2FF8(void);
extern s32 func_004C2F28(s32);
extern s32 func_004976C8(s32 *, s32, s32, void (*)(void), void (*)(void), s32 (*)(s32));
extern void func_00497980(s32);
extern void func_004C2610(void);
void func_004C30B8(s32 a)
{
    State *p = &D_0030B7F8[func_00505B20()];
    if (func_004976C8(&p->choice, 10, a, func_004C2F78, func_004C2FF8, func_004C2F28)) {
        func_00497980(15);
        func_004C2610();
        p->flags |= 1;
    }
}
