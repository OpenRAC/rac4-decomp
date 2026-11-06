#include "common.h"
typedef struct {
    s32 f0, f4, flags, fC, selection;
    char tail[0x60];
} State;
extern State D_0030B7F8[];
extern s32 D_00221888;
extern s32 func_00505B20(void), func_004A1A60(s32 *, s32), func_00506358(u32);
extern void func_004C3140(void), func_004C31A8(void), func_00497980(s32);
extern s32 func_004976C8(s32 *, s32, s32, void (*)(void), void (*)(void), s32 (*)(s32));
void func_004C3250(s32 reverse)
{
    State *p = D_0030B7F8 + func_00505B20();
    if (func_004976C8(&p->selection, 3, reverse, func_004C3140, func_004C31A8, 0)) {
        func_00497980(0);
        func_00506358(func_004A1A60(&D_00221888, 83));
        func_00506358(func_004A1A60(&D_00221888, 80));
        func_00506358(func_004A1A60(&D_00221888, 81));
        p->flags |= 8;
    }
}
