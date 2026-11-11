/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004E4578 (src/levels/39_multiplayer_menu/L39_004E3B68.c, GPL-3.0), the same code in both games. */

extern void *func_L00_004FACD8(s32);
extern void func_L00_004FAD28(void *);
extern void func_0011A370(void *, void *, s32);
typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    void *fC;
    s32 f10;
    s32 f14;
} Type1;
s32 func_L00_00520378(Type1 *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4, s32 arg5) {
    void *p;
    if ((arg5 & 2) && arg3 != 0 && arg4 != 0) {
        p = func_L00_004FACD8(arg4);
        if (p == 0) {
            return 1;
        }
        func_0011A370(p, arg3, arg4);
        if (arg0->fC != 0 && (arg0->f14 & 2)) {
            func_L00_004FAD28(arg0->fC);
        }
        arg0->fC = p;
        arg0->f14 |= 2;
    } else {
        if (arg0->fC != 0 && (arg0->f14 & 2)) {
            func_L00_004FAD28(arg0->fC);
        }
        arg0->fC = arg3;
        arg0->f14 &= ~2;
    }
    arg0->f0 = arg1;
    arg0->f4 = arg2;
    arg0->f10 = arg4;
    arg0->f8 = 0;
    return 0;
}
