#include "common.h"

extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern u64 func_00548DA0(u8 *a0, s32 a1);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_003D92A0[];
s32 D_0021F728 = 0;

// Returns whether entry arg0 of D_003D92A0 has a zero first word when both flags are clear, else the inverted bit test on the state.
u8 func_004AE820(s32 arg0) {
    if (D_0021EDD4 == 0 && D_0021EDD8 == 0) {
        return *(s32 *)((u8 *)D_003D92A0 + arg0 * 0xC) == 0;
    }
    return (u8)(func_00548DA0(*(u8 **)((u8 *)func_00510BE8(func_00505B20()) + 0x26E4), ((s32 *)&D_0021F728)[arg0]) ^ 1);
}
