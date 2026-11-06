/* Not matching yet: SIZE ours 104 / disc 112 (tools/try_func.py func_004E80F8 --diff). Not part of the build. */
/* Retail builds the register's address as a constant (lui/ori, then an access at 0): only
 * `*(volatile u32 *)0x1000E010` gives that, and matched C may use neither volatile nor
 * hardcoded addresses. A global named by its address gives lui/%lo instead. */
#include "common.h"
extern s32 D_00221E48;
extern s32 D_00221E4C;
extern u32 D_1000E010;
extern void func_001268D0(s32, s32);
extern void func_001276D0(s32);
void func_004E80F8(void) {
    if (D_1000E010 & 0x20000) {
        D_1000E010 = 0x20000;
    }
    func_001268D0(1, D_00221E48);
    func_001268D0(15, D_00221E4C);
    func_001276D0(1);
    D_00221E48 = 0;
    D_00221E4C = 0;
}
