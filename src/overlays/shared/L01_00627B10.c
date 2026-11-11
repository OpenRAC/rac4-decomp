#include "common.h"

typedef int u128_4B75B0 __attribute__((mode(TI)));
typedef struct { u16 id; u8 pad2[30]; u128_4B75B0 v0; u128_4B75B0 v1; u8 a; u8 pad41[15]; } Ent_004B75B0;
extern Ent_004B75B0 D_0034CF60[];

/* from rac3-decomp's func_L04_004BB2E0 */
s32 func_L01_00627B10(u32 a0, u128_4B75B0 *a1, u128_4B75B0 *a2) {
    u32 idx = a0 >> 16;
    Ent_004B75B0 *e = 0;
    if (idx < 12) {
        Ent_004B75B0 *p = &D_0034CF60[idx];
        if (p->a != 0 && p->id == (a0 & 0xFFFF)) e = p;
    }
    if (e) {
        e->v0 = *a1;
        e->v1 = *a2;
        return 1;
    }
    return 0;
}
