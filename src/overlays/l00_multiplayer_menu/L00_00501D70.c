/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C5F70 (src/levels/39_multiplayer_menu/L39_004C5F70.c, GPL-3.0), the same code in both games. */

extern s32 func_L00_00501E98(s32);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
typedef struct Type1 {
    s32 pad0[15];
    u8 **p3C;
    s32 f40;
} Type1;
s32 func_L00_00501D70(Type1 *arg0, s64 arg1, s32 arg2) {
    if (arg0->f40 == 0 && arg2 >= 3) {
        u8 *p = arg0->p3C[1];
        if (p[0] == 0) {
            func_L00_004F84C8(0x14, arg1, func_L00_00501E98((p[1] << 8) | p[2]), 0, 0);
        }
    }
    if (arg2 < 0) {
        return arg2;
    }
    arg0->f40 += arg2;
    return 0;
}
