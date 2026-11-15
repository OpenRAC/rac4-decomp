#include "common.h"

/* The level 41 instance is a getter; other overlay instances have different callees. */
extern s32 func_L00_006215A0(s32);
extern s32 func_L41_005C5AC8(s32, u8 *);
extern void func_00506B70(s32);
extern s32 func_00506BB8(void);
extern s32 D_00381550[];

s32 func_L41_0040EC00(s32 arg0)
{
    s32 previous;
    s32 index;
    u8 value[16];

    value[0] = 0;
    previous = func_00506BB8();
    func_00506B70(arg0);
    index = func_L00_006215A0(arg0);
    func_L41_005C5AC8(D_00381550[index], value);
    func_00506B70(previous);
    return value[0];
}
