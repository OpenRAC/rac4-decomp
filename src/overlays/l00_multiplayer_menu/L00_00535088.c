/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004F9278 (src/levels/39_multiplayer_menu/L39_004F8A78.c, GPL-3.0), the same code in both games. */

extern void *func_L00_004FACD8(s32);
extern void func_L00_004FAD28(void *);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
char *func_L00_00535088(s32 (*i2d)(), char *(*d2i)(), char *x) {
    u8 *b, *p;
    long i;
    char *ret;
    if (x == 0) {
        return 0;
    }
    i = (long)i2d(x, 0);
    b = (u8 *)func_L00_004FACD8((u32)i + 10);
    if (b == 0) {
        func_L00_004F84C8(13, 106, 33, 0, 0);
        return 0;
    }
    p = b;
    i = i2d(x, &p);
    p = b;
    ret = d2i(0, &p, i);
    func_L00_004FAD28(b);
    return ret;
}
