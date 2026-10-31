#include "common.h"

extern void func_00497980(s32);
extern s32 func_004A1A60(s32 *, s32);
extern void func_00505238(s32, s32);
extern u8 D_00171D38[];
extern s32 D_003D95C0[];
extern s32 D_2217E0;
extern u8 D_30A4E0[];
/* Toggles a flag byte when arg0 is nonzero, then calls func_00505238 with a table entry selected by that flag. */
void func_004BA490(s32 arg0) {
    if (arg0 != 0) {
        D_00171D38[5] = (u8) (D_00171D38[5] == 0);
        func_00497980(0x10);
    }
    func_00505238(func_004A1A60(&D_2217E0, D_003D95C0[0]), (s32) (D_30A4E0 + D_00171D38[5] * 0x30));
}
