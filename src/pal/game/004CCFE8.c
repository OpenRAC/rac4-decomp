#include "common.h"

extern s32 D_0021EE54, D_0021EE58;
extern s32 D_00221A20;
extern s32 D_003D27D8[], D_003D27A8[];
extern s32 func_004A2798(s32 *, s32);
extern void func_004CE4C0(s32);
extern s32 func_00506BB8(void);
extern void func_0049CE90(s32, s32, s32, s32);
extern s32 func_005063C0(s32, u32);

/* Set the selection's alpha and resource color for the current slot. */
void func_004CCFE8(s32 selection)
{
    s32 active = 1;
    s32 index;
    if (D_0021EE54 || D_0021EE58 != 1)
        active = selection >= 8;
    func_004CE4C0(active);
    index = func_00506BB8();
    func_0049CE90(index, 0, func_004A2798(&D_00221A20, D_003D27D8[selection]), 0);
    func_005063C0(func_004A2798(&D_00221A20, D_003D27A8[selection]), 0x80D0D0D0u);
}
