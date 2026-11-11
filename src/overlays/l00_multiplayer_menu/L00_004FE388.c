/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C2588 (src/levels/39_multiplayer_menu/L39_004C2588.c, GPL-3.0), the same code in both games. */

typedef struct {
    u8 pad0[0x94];
    void *f94;
    u8 pad98[0x14];
    void *fAC;
    u8 padB0[0x18];
    void *fC8;
    u8 padCC[0x2C];
    void *fF8;
    void *fFC;
} Type1;
typedef struct { u8 pad0[0x54]; Type1 *f54; } T_004C2588;
extern void func_L00_0051A7B8(void *);
extern void func_L00_004FAD28(void *);
extern void func_L00_004FE578(void *);
extern void func_0011A518(void *, s32, s32);
void func_L00_004FE388(T_004C2588 *arg0) {
    if (arg0->f54->fF8 != 0) {
        func_L00_0051A7B8(arg0->f54->fF8);
    }
    if (arg0->f54->fFC != 0) {
        func_L00_0051A7B8(arg0->f54->fFC);
    }
    if (arg0->f54->f94 != 0) {
        func_L00_004FAD28(arg0->f54->f94);
    }
    if (arg0->f54->fAC != 0) {
        func_L00_004FAD28(arg0->f54->fAC);
    }
    if (arg0->f54->fC8 != 0) {
        func_L00_004FAD28(arg0->f54->fC8);
    }
    func_L00_004FE578(arg0);
    func_0011A518(arg0->f54, 0, 0x198);
    func_L00_004FAD28(arg0->f54);
    arg0->f54 = 0;
}
