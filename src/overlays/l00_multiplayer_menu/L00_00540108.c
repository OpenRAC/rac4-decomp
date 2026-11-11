/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_005042F8 (src/levels/39_multiplayer_menu/L39_005013E0.c, GPL-3.0), the same code in both games. */

extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    void *fC;
    s32 f10;
    s32 f14;
} Type1;
extern void *func_L00_004FACD8(s32);
extern void func_0011A518(void *, s32, s32);
extern void *func_L00_0051EB20(void);
extern s32 func_L00_005205A8(void);
extern s32 func_L00_00520E90(void);
extern s32 func_L00_005206A8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L00_0051EB68(void *);
extern void func_L00_005205F8(s32);
extern void func_L00_004FAD28(void *);
Type1 *func_L00_00540108(s32 arg0) {
    Type1 *ret = 0;
    Type1 *p;
    if (arg0 == 0) {
        func_L00_004F84C8(5, 0x69, 0xE, 0, 0);
        return 0;
    }
    p = func_L00_004FACD8(0x18);
    if (p == 0) {
        func_L00_004F84C8(5, 0x69, 0x21, 0, 0);
        return 0;
    }
    func_0011A518(p, 0, 0x18);
    p->f8 = arg0;
    if ((p->fC = func_L00_0051EB20()) != 0) {
        if ((p->f4 = func_L00_005205A8()) != 0) {
            p->f10 = 1;
            func_L00_005206A8(p->f4, 1, 2, 0, func_L00_00520E90(), 0, 0);
            ret = p;
            p = 0;
        }
    }
    if (p != 0) {
        if (p->fC != 0) {
            func_L00_0051EB68(p->fC);
        }
        if (p->f4 != 0) {
            func_L00_005205F8(p->f4);
        }
        func_L00_004FAD28(p);
    }
    return ret;
}
