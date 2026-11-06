#include "common.h"

extern s32 D_0021EDD4, D_0021EDD8;
extern s32 D_00221920;
extern s32 D_003D2768[], D_003D2738[];
extern s32 func_004A1A60(s32 *, s32);
extern void func_004CD620(s32);
extern s32 func_00505B20(void);
extern void func_0049C158(s32, s32, s32, s32);
extern s32 func_00505328(s32, u32);

/* Set the selection's alpha and resource color for the current slot. */
void func_004CC148(s32 selection)
{
    s32 active = 1;
    s32 index;
    if (D_0021EDD4 || D_0021EDD8 != 1)
        active = selection >= 8;
    func_004CD620(active);
    index = func_00505B20();
    func_0049C158(index, 0, func_004A1A60(&D_00221920, D_003D2768[selection]), 0);
    func_00505328(func_004A1A60(&D_00221920, D_003D2738[selection]), 0x80D0D0D0u);
}
