#include "common.h"
typedef struct {
    s32 f0, f4, flags, fC, selection;
    char tail[0x60];
} State;
extern State D_0030B7F8[];
extern s32 D_00221988;
extern s32 func_00506BB8(void), func_004A2798(s32 *, s32), func_005073F0(u32);
extern void func_004C3F68(void), func_004C3FD0(void), func_004985F0(s32);
extern s32 func_00498320(s32 *, s32, s32, void (*)(void), void (*)(void), s32 (*)(s32));
void func_004C4078(s32 reverse)
{
    State *p = D_0030B7F8 + func_00506BB8();
    if (func_00498320(&p->selection, 3, reverse, func_004C3F68, func_004C3FD0, 0)) {
        func_004985F0(0);
        func_005073F0(func_004A2798(&D_00221988, 83));
        func_005073F0(func_004A2798(&D_00221988, 80));
        func_005073F0(func_004A2798(&D_00221988, 81));
        p->flags |= 8;
    }
}
