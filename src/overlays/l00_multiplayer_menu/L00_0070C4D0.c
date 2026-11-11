#include "common.h"
/* Ported from rac3-decomp's func_L39_006CC2E8 (src/levels/39_multiplayer_menu/L39_006CC1C0.c, GPL-3.0), the same code in both games. */

extern void func_L00_0070C418(s32 arg0, s32 *arg1, s32 *arg2);
extern s32 func_L00_0070C4D0(s32, s32, s32);
s32 func_L00_0070C4D0(s32 a0, s32 a1, s32 a2)
{
    s32 f[2];
    s32 *p = (s32 *)a1;
    func_L00_0070C418(a0, &f[0], &f[1]);
    *p = (*p & ~f[0]) | (a2 << f[1]);
}
