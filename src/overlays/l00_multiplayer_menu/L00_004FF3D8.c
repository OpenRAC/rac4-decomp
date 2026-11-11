/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C35D8 (src/levels/39_multiplayer_menu/L39_004C3428.c, GPL-3.0), the same code in both games. */

extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
typedef struct Type1 {
    s32 f0;
} Type1;
typedef struct Type2 {
    u8 pad0[0x18];
    s32 f18;
    u8 pad1c[0x74];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
} Type2;
typedef struct Type3 {
    u8 pad0[0xDC];
    Type2 *fDC;
    u8 padE0[8];
    long fE8;
} Type3;
extern s32 func_L00_004F8148(void *, void *, s32, s32, void *);
extern s32 func_L00_004F8190(void *, void *, s32, s32, s32, void *);
extern void func_L00_00519EC8(void);
s32 func_L00_004FF3D8(Type3 *arg0, Type1 *arg1) {
    Type2 *t;
    s32 r;
    if (arg1 == 0 || arg1->f0 == 0) {
        return 0;
    }
    t = arg0->fDC;
    if (t->f98 != 0) {
        r = func_L00_004F8148(arg0, arg1, t->f98, t->f9C, &arg0->fE8);
    } else {
        r = func_L00_004F8190(arg0, arg1, t->f18, t->f90, t->f94, &arg0->fE8);
    }
    if (arg0->fE8 == 0x32) {
        func_L00_004F84C8(0x14, 0xD0, 0xC2, 0, 0);
    }
    if (r != 0) {
        func_L00_00519EC8();
    }
    return r;
}
