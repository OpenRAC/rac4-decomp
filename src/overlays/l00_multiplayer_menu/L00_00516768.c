/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004DA968 (src/levels/39_multiplayer_menu/L39_004DA968.c, GPL-3.0), the same code in both games. */

void *func_L00_004FACD8(s32);
void func_L00_004FAD28(void *);
void func_L00_004F84C8(s32, s32, s32, s32, s32);
s32 func_L00_005167E8(void *, s32);
void *func_L00_00516768(s32 arg0) {
    void *p = func_L00_004FACD8(0x48);
    if (p == 0) {
        func_L00_004F84C8(0x20, 0x67, 0x21, 0, 0);
        return 0;
    }
    if (func_L00_005167E8(p, arg0) == 0) {
        func_L00_004FAD28(p);
        p = 0;
    }
    return p;
}
extern void func_L00_004F84C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
