/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C28F0 (src/levels/39_multiplayer_menu/L39_004C2588.c, GPL-3.0), the same code in both games. */

extern s32 func_L00_005193E0(s32);
extern s32 func_L00_005192C0(s32);
extern void func_L00_00519050(s32);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
s32 func_L00_004FE6F0(s32 *arg0, s32 arg1) {
    s32 p = func_L00_005193E0(arg1);
    if (p == 0 || func_L00_005192C0(p) == 0) {
        func_L00_004F84C8(0x14, 0xD6, 0x805, 0, 0);
        return 0;
    }
    if (*arg0 != 0) {
        func_L00_00519050(*arg0);
    }
    *arg0 = p;
    return 1;
}
