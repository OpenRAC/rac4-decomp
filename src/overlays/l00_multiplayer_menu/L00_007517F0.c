#include "common.h"

extern s32 func_L00_00709318(s32 arg0, s32 arg1, s32 arg2);
extern void func_L00_00709378(s32 arg0, s32 arg1);
extern void func_L00_00751980(void);
extern s32 D_00223408;

// Registers func_L00_00751980 with func_L00_00709318 and stores the handle it returns.
void func_L00_007517F0(void) {
    s32 temp_v0;

    temp_v0 = func_L00_00709318(func_L00_00751980, 0, 0);
    D_00223408 = temp_v0;
    func_L00_00709378(temp_v0, 1);
}
