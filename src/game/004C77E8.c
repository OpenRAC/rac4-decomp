#include "common.h"
extern s32 func_00505B20(void);
extern void func_0049B1A0(s32, s32);
extern u8 D_0021F8E8, D_0021F93A, D_0021F938;
/* Set the three entry flags and select the operation for the current slot. */
void func_004C77E8(void)
{
    s32 slot = func_00505B20();
    D_0021F93A = 1;
    D_0021F938 = 1;
    D_0021F8E8 = 1;
    func_0049B1A0(slot, 21);
}
