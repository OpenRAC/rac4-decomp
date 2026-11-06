#include "common.h"

/* Clears the transition flags and resets the current slot when a transition is active. */
extern s32 D_0021F218;
extern u8 D_0021F9DB, D_0021F988, D_0021F9D9, D_0021F9DA, D_0021F9D8;
extern void func_00499A30(void);
extern s32 func_00506BB8(void);
extern void func_0049C030(s32, s32);
void func_004CFEE0(void)
{
    if (D_0021F218 != -1) {
        func_00499A30();
        D_0021F9DB = 0;
        D_0021F988 = 0;
        D_0021F9D9 = 0;
        D_0021F9DA = 0;
        D_0021F9D8 = 0;
        func_0049C030(func_00506BB8(), -1);
    }
}
