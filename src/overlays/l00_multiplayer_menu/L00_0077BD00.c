#include "common.h"
/* Ported from rac3-decomp's func_L39_006DD770 (src/levels/39_multiplayer_menu/L39_006DC228.c, GPL-3.0), the same code in both games. */

extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
typedef struct {
    s32 x[0x5C / 4];
} Type1;
typedef struct {
    u8 b0;
    Type1 blk;
} Type2;
typedef struct {
    char _p0[0x1D];
    u8 b1D;
    char _p1E[0x68 - 0x1E];
    Type2 *f54;
} Type3;
void func_L00_0077BD00(Type1 *arg0) {
    Type3 *g = (Type3 *)D_002233A4;
    Type2 *st = g->f54;
    if (g->b1D == 0) {
        st->b0 = 0;
        st->blk = *arg0;
    }
}
extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
extern void *D_002233A4;
