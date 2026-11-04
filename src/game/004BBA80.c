#include "common.h"

/* Sets the transition flags and schedules mode 21 for the current slot. */
extern u8 D_0021F939, D_0021F938, D_0021F93A;
u8 D_0021F8E8 = 0;
extern s32 D_0021DE10;
extern s32 func_00505B20(void);
extern void func_0049B1A0(s32, s32);
void func_004BBA80(void)
{
    if ((D_0021F939 || D_0021DE10 != 15) && D_0021DE10 != 35) {
        s32 slot = func_00505B20();
        D_0021F938 = 1;
        D_0021F93A = 1;
        D_0021F8E8 = 1;
        func_0049B1A0(slot, 21);
    }
}
