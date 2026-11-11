/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004FAAB0 (src/levels/39_multiplayer_menu/L39_004FA638.c, GPL-3.0), the same code in both games. */

typedef struct { s32 a; s32 b; s32 ok; s32 c; } Type1;
extern void *func_L00_004FACD8(s32);
extern s32 func_L00_00508028(s32);
extern s32 func_L00_00516F10(void);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
Type1 *func_L00_005368C0(void) {
    Type1 *p;
    s32 err[12];
    p = func_L00_004FACD8(0x18);
    if (p == 0) {
        err[11] = 0xDB;
        goto fail;
    }
    p->a = 0;
    p->b = func_L00_00508028(0);
    if (p->b == 0) {
        err[11] = 0xDE;
        goto fail;
    }
    p->c = func_L00_00516F10();
    if (p->c == 0) {
        return 0;
    }
    p->ok = 1;
    return p;
fail:
    func_L00_004F84C8(0xD, 0xD4, 0x21, 0, 0);
    return 0;
}
