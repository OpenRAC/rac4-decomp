#include "common.h"

extern void func_0061F260(s32);
extern s32 func_006294E0(s32 *, s32);
extern void func_L00_0069D318(s32, s32);
extern u8 D_00171D38[];
extern s32 D_004CA5E0[];
extern s32 D_00222870;
extern u8 D_003102E0[];
/* Toggles a flag byte when arg0 is nonzero, then calls func_L00_0069D318 with a table entry selected by that flag. */
void func_L00_00642310(s32 arg0) {
    if (arg0 != 0) {
        D_00171D38[5] = (u8) (D_00171D38[5] == 0);
        func_0061F260(0x10);
    }
    func_L00_0069D318(func_006294E0(&D_00222870, D_004CA5E0[0]), (s32) (D_003102E0 + D_00171D38[5] * 0x30));
}
