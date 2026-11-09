/* Not matching yet: SIZE ours 148 / disc 208 (tools/try_func.py func_004E7450 --diff). Not part of the build. */
/* Retail builds the hardware register's address as a constant (lui/ori): only a
 * `*(volatile s32 *)0x...` cast gives that, and matched C may use neither volatile nor
 * hardcoded addresses. This plain-C version names the registers as globals instead.
 * The volatile version was exact (AUT-46); it left src/ under the new rules. */
#include "common.h"
extern s32 D_10008000;
extern s32 D_10008020;
extern s32 D_10008030;

void func_004535E0(s32);

s32 D_002206EC = 0;

void func_004E7450(s32 arg0) {
    if (arg0 != D_002206EC) {
        if (D_10008000 & 0x100) {
            do {
                func_004535E0(0x10);
            } while (D_10008000 & 0x100);
        }
        D_10008020 = 0;
        D_10008030 = arg0 & 0x0FFFFFFF;
        D_10008000 = 0x145;
        D_002206EC = arg0;
        if (D_10008000 & 0x100) {
            do {
                func_004535E0(0x10);
            } while (D_10008000 & 0x100);
        }
    }
}
