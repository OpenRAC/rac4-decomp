#include "common.h"

typedef struct { s32 w0; s32 w4; f32 f8; s32 wC; void *w10; } P_524888;
typedef struct { u8 p0[0x400]; P_524888 p; u8 pad[0x470 - 0x400 - 0x14]; } E_524888;
extern E_524888 D_00230380[];
void func_L01_005248D0(s32 a0);

/* PAL: from rac3-decomp's func_L03_003DA010 */
void func_L01_00524888(s32 i) {
    E_524888 *e = &D_00230380[i];
    P_524888 *p = &e->p;
    p->w4 = 0;
    e->p.w0 = 0;
    p->f8 = 10000.0f;
    p->wC = 0;
    p->w10 = ((void (*)(void))func_L01_005248D0);
}
