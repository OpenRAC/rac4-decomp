#include "common.h"
extern s32 func_00506BB8(void);
extern void func_0049BED8(s32, s32);
extern u8 D_0021F988, D_0021F9DA, D_0021F9D8;
/* Set the three entry flags and select the operation for the current slot. */
void func_004C8610(void)
{
    s32 slot = func_00506BB8();
    D_0021F9DA = 1;
    D_0021F9D8 = 1;
    D_0021F988 = 1;
    func_0049BED8(slot, 21);
}
