/* cflags: @ee296 -O2 -G0 */
#include "common.h"
extern u32 D_00356184;
extern u32 D_00356188;
extern s32 D_00356190;
extern s32 D_003561A0;
extern s32 D_003561A4;
extern s32 D_003561A8;
extern u32 D_003561B0;
u32 func_003F9748(s32 a) {
    u32 old = D_00356188;
    u32 n = old + (a << D_00356190);
    u32 t;
    if (D_00356184 < n) return 0;
    D_00356188 = n;
    t = ((n + D_003561A0) >> D_00356190) - D_003561A4;
    D_003561A8 = t - 1;
    return t < D_003561B0 ? old : 0;
}
