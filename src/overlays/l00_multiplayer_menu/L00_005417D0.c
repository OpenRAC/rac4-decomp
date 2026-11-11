/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_005059C0 (src/levels/39_multiplayer_menu/L39_005051E0.c, GPL-3.0), the same code in both games. */

extern void func_0011A518(void *, s32, s32);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8(s32);
extern void func_L00_004FAD28(void *);
typedef struct {
    s32 f0;
    void *f4;
    void *f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
} Type1;
extern void *func_L00_005205A8(void);
extern s32 func_L00_00520E90(void);
extern void func_L00_005206A8(void *, s32, s32, s32, s32, s32, s32);
extern void func_L00_005205F8(void *);
Type1 *func_L00_005417D0(void *arg0) {
    Type1 *p;
    Type1 *ret = 0;
    if (arg0 == 0) {
        func_L00_004F84C8(4, 0x6B, 0xE, 0, 0);
        return 0;
    }
    p = func_L00_004FACD8(0x1C);
    if (p == 0) {
        func_L00_004F84C8(4, 0x6B, 0x21, 0, 0);
        return 0;
    }
    func_0011A518(p, 0, 0x1C);
    p->f8 = arg0;
    p->f10 = 1;
    p->fC = 0;
    p->f18 = 0;
    p->f4 = func_L00_005205A8();
    if (p->f4 != 0) {
        p->f10 = 1;
        func_L00_005206A8(p->f4, 1, 2, 0, func_L00_00520E90(), 0, 0);
        func_L00_005206A8(p->f4, 1, 3, 0, 0, 0, 0);
        ret = p;
        p = 0;
    }
    if (p != 0) {
        if (p->f4 != 0) {
            func_L00_005205F8(p->f4);
        }
        func_L00_004FAD28(p);
    }
    return ret;
}
