#include "common.h"

typedef struct { u8 pad[0x2B8]; s32 x2B8; s32 x2BC; u8 pad2C0[0x2D8 - 0x2C0]; s32 x2D8; } X_006F45A8;
typedef struct { u8 pad[0x2EF4]; X_006F45A8 *x2EF4; u8 pad2[0x2F18 - 0x2EF8]; s32 x2F18; } P_006F45A8;
extern s32 D_001721F0[];

/* PAL: from rac3-decomp's func_L39_006683F8 */
void func_L00_006F45A8(P_006F45A8 *p, s32 a1) {
    X_006F45A8 *x;
    s32 v;
    a1 = a1 + 1;
    if (a1 >= 10) a1 = 0;
    x = p->x2EF4;
    if (x == 0) return;
    v = p->x2F18;
    if (v == 5 || v == 3) {
        x->x2B8 = 0;
        if (D_001721F0[0] == a1) {
            p->x2EF4->x2D8 |= 4;
            p->x2EF4->x2D8 |= 2;
            p->x2EF4->x2D8 &= 0xFFFFFFDF;
        }
    } else if (v == 6 || v == 4) {
        x->x2BC = 0;
    }
    p->x2EF4 = 0;
    p->x2F18 = 0;
}
