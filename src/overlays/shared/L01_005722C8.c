#include "common.h"
typedef struct {
    s32 a[8];
    s32 b[8];
    s32 c[8];
    s32 d[8];
    u16 e[8];
    u8 pad[1];
    u8 n;
} T;
s32 func_L01_005722C8(T *t)
{
    s32 i;
    if (t == 0) {
        return 1;
    }
    for (i = 0; i < 8; i++) {
        t->a[i] = 0;
        t->b[i] = 0;
        t->c[i] = 0;
        t->d[i] = 0;
        t->e[i] = 0x801;
    }
    t->n = 0;
    return 1;
}
