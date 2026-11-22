#include "common.h"
typedef struct {
    f32 a[8];
    f32 b[8];
    u8 padc[0x20];
    f32 c[8];
    u16 e[8];
    u8 pad[1];
    u8 n;
} T;
s32 func_L01_00572430(T *t, s32 i)
{
    s32 n;
    if (t == 0) {
        return 1;
    }
    if (i < 0) {
        return 1;
    }
    n = t->n;
    if (i >= n) {
        return 1;
    }
    n--;
    t->n = n;
    if (i < (n & 0xFF)) {
        do {
            t->a[i] = t->a[i + 1];
            t->b[i] = t->b[i + 1];
            t->c[i] = t->c[i + 1];
            t->e[i] = t->e[i + 1];
            i++;
        } while (i < t->n);
    }
    return 1;
}
