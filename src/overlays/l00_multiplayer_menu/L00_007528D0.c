#include "common.h"

extern void func_00751B78(void *, s32, void *);
extern void func_L00_00751BA8(void *);
extern void func_L00_007533F0(void *, s32);
extern s32 D_003DB030[];
extern s32 D_00171948[];
extern s32 D_002213D4;
s32 D_002213BC = 0;
extern s32 D_002213B8;

/* advances the menu state when idle */
void func_L00_007528D0(u8 *arg0) {
    D_002213D4 = 3;
    if (D_00171948[2] == 2 && D_00171948[0x75] == 0) {
        func_00751B78(arg0, 3, D_00171948);
        if (D_002213BC != 0) {
            func_L00_00751BA8((u8 *)D_003DB030 + D_002213B8 * 0x1E0);
            D_002213BC = 0;
        }
        func_L00_007533F0(arg0, 0);
        arg0[0x280] = 1;
    }
}
