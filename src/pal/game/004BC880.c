#include "common.h"

/* Sets the transition flags and schedules mode 21 for the current slot. */
extern u8 D_0021F9D9, D_0021F9D8, D_0021F9DA;
u8 D_0021F988 = 0;
extern s32 D_0021DE98;
extern s32 func_00506BB8(void);
extern void func_0049BED8(s32, s32);
void func_004BC880(void)
{
    if ((D_0021F9D9 || D_0021DE98 != 15) && D_0021DE98 != 35) {
        s32 slot = func_00506BB8();
        D_0021F9D8 = 1;
        D_0021F9DA = 1;
        D_0021F988 = 1;
        func_0049BED8(slot, 21);
    }
}
