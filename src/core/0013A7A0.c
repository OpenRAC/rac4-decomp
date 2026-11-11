/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_0012E2E0 (src/boot_elf/core/12E050.c, GPL-3.0), the same code in both games. */

extern int func_0013A7A0();
extern s32 func_00126BF0(s32);
extern s32 func_00126BC0(s32);
extern int func_00126BC0();
extern int func_00126BF0();
extern int D_00167BFC;
extern int D_00167C00;
extern u8 D_001AEE40[];
extern s32 D_00167BFC;
extern s32 D_00167BF8[];
extern s32 D_00167BF8[];
extern s32 D_00167BFC;
extern u8 D_001AEE40[];
extern u8 D_001AEE40[];
extern s32 D_00167BFC;
extern u8 D_001AEE40[];
extern s32 D_00167BFC;
extern s32 D_00167BF8[];
extern void func_00126BE0(s32);
extern s32 D_00167C00;
s32 func_0013A7A0(s32 mode, s32 *cmd, s32 *result) {
    s32 busy;
    if (D_00167BF8[0] == 0) {
        return -1;
    }
    busy = 0;
    if (func_00126BF0(D_00167C00) < 0) {
        busy = 1;
    }
    if (mode == 0 && busy) {
        func_00126BE0(D_00167C00);
        busy = 0;
    }
    busy = !busy;
    if (cmd != 0) {
        *cmd = D_00167BF8[0];
    }
    if (busy != 0) {
        D_00167BF8[0] = 0;
        if (result != 0) {
            *result = *(s32 *)D_001AEE40;
        }
        func_00126BC0(D_00167BFC);
    }
    return busy;
}
