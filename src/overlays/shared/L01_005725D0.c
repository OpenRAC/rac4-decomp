#include "common.h"
typedef struct { s32 t; u16 a; u16 b; u16 c; u16 d; u16 e; } Ent;
extern s32 D_0021DDB8;
extern Ent D_0024B0A0[];
s32 func_L01_005725D0(Ent **out)
{
    s32 i;
    Ent *e;
    if (out == 0) return 1;
    for (i = 1; i < 8; i++) {
        e = &D_0024B0A0[i];
        if (e->t < D_0021DDB8 || e->b == 0 || e->e == 0xFFFF) {
            *out = e; e->a = 0; (*out)->d = 0; return 1;
        }
    }
    return 1;
}
