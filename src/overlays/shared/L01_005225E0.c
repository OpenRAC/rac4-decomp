#include "common.h"

typedef struct { s32 w0; s32 w4; f32 f8; s32 wC; void *w10; } P_5225E0;
typedef struct { u8 p0[0x400]; P_5225E0 p; u8 pad[0x470 - 0x400 - 0x14]; } E_5225E0;
extern E_5225E0 D_00230280[];
extern void func_L01_00522628(s32 a0);

/* from rac3-decomp's func_L03_003DA010 */
void func_L01_005225E0(s32 i) {
    E_5225E0 *e = &D_00230280[i];
    P_5225E0 *p = &e->p;
    p->w4 = 0;
    p->w0 = 0;
    p->f8 = 10000.0f;
    p->wC = 0;
    p->w10 = func_L01_00522628;
}
