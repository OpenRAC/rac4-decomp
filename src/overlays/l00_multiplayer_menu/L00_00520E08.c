/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004E5008 (src/levels/39_multiplayer_menu/L39_004E5008.c, GPL-3.0), the same code in both games. */

extern void func_L00_004FAD28(void *);
typedef struct Type1 {
    s32 f0;
    s32 f4;
    void (*f8)(void *, s32, void *);
    s32 fC;
    s32 f10;
} Type1;
void func_L00_00520E08(Type1 *arg0) {
    if (arg0 == 0) {
        return;
    }
    if (arg0->f8 != 0) {
        arg0->f8(arg0, 2, arg0);
    }
    if (arg0->f10 & 1) {
        func_L00_004FAD28(arg0);
    }
}
