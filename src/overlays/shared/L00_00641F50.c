#include "common.h"

extern u8 D_00171D38[];
extern s32 D_004CA568[];
extern s32 D_00222870;
extern u8 D_003102E0[];
extern void func_0061F260(s32 arg0);
extern s32 func_006294E0(s32 *arg0, s32 arg1);
extern void func_L00_0069D318(s32, void *, s32);

/* Toggles byte 6 of D_00171D38 when arg0 is set, then passes a 0x30-byte slot of D_003102E0 to func_L00_0069D318. */
void func_L00_00641F50(s32 arg0) {
    if (arg0 != 0) {
        D_00171D38[6] = (u8)(D_00171D38[6] == 0);
        func_0061F260(0x10);
    }
    func_L00_0069D318(func_006294E0(&D_00222870, D_004CA568[0]), D_00171D38[6] * 0x30 + D_003102E0, 0x30);
}
