#include "common.h"
/* Ported from rac3-decomp's func_L39_006D7838 (src/levels/39_multiplayer_menu/L39_006D4ED8.c, GPL-3.0), the same code in both games. */

s32 func_0012E370(void);
long func_0012FEB0(s32, long);
void func_L00_00772C60(void *);
s32 func_L00_007730B0(u8 *arg0) {
    s32 ret = 1;
    if (arg0[0] != 0) {
        s32 t = func_0012FEB0(func_0012E370(), 0x24000);
        if (t - *(s32 *)(arg0 + 4) >= 0x3A99) {
            arg0[0] = 0;
            func_L00_00772C60(arg0);
            ret = 0;
        }
    }
    return ret;
}
extern s32 func_0012E370(void);
extern long func_0012FEB0(s32, long);
s32 func_L00_007730B0(u8 *);
