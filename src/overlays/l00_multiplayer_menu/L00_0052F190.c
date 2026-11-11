/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004F3390 (src/levels/39_multiplayer_menu/L39_004F3390.c, GPL-3.0), the same code in both games. */

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
} Type1;
extern Type1 *func_L00_004FACD8(s32);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_00536290(s32);
extern s32 func_L00_005423D8(void);
extern s32 func_L00_005368C0(void);
extern s32 func_L00_00530190(void);
extern s32 func_L00_0052F9C0(void);
Type1 *func_L00_0052F190(void) {
    Type1 *o = func_L00_004FACD8(0x28);
    if (o == 0) {
        s32 err[12];
        err[11] = 0x76;
        func_L00_004F84C8(13, 204, 33, 0, 0);
        return 0;
    }
    o->f0 = 0;
    if (!(o->f4 = func_L00_00536290(2))) return 0;
    if (!(o->f8 = func_L00_005423D8())) return 0;
    if (!(o->fC = func_L00_005368C0())) return 0;
    if (!(o->f10 = func_L00_00530190())) return 0;
    if (!(o->f14 = func_L00_005368C0())) return 0;
    if (!(o->f18 = func_L00_0052F9C0())) return 0;
    o->f1C = 0;
    o->f20 = 0;
    o->f24 = 0;
    return o;
}
