#include "common.h"

extern void func_L00_00751BA8(void *);
extern void func_L00_007533F0(void *, s32);
extern s32 D_003DB030[];
extern s32 D_00171950[];
s32 D_002213B8 = 0;
s32 D_002213D4 = 0;

/* resets the menu state and advances the state machine */
void func_L00_007527E8(u8 *arg0) {
    s32 temp;

    arg0[0x281] = 0;
    temp = D_00171950[0];
    if (temp == 2) {
        D_002213D4 = temp;
        return;
    }
    func_L00_00751BA8((u8 *)D_003DB030 + D_002213B8 * 0x1E0);
    func_L00_007533F0(arg0, 0);
    D_002213D4 = 3;
}
