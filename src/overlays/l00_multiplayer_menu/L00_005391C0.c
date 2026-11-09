/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef union {
    u64 v;
    u32 w[2];
} Type2;

typedef struct {
    Type2 *f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Type1;

extern int func_L00_005382C8(int a1, int a2);
extern s32 func_L00_00539310(Type1 *a0, u64 a1);

/* Adds a 64-bit word to a signed multi-word number. */
s32 func_L00_005391C0(Type1 *p, u64 w)
{
    s32 i;
    s32 n;
    u64 v;

    if (w == 0) {
        return 1;
    }
    if (p->fC != 0) {
        if (p->f4 >= 2) {
            s32 r;
            p->fC = 0;
            r = func_L00_00539310(p, w);
            p->fC = 1;
            return r;
        }
        v = p->f0[0].v;
        if (v > w) {
            p->f0[0].v = v - w;
        } else if (v < w) {
            p->fC = 0;
            p->f0[0].v = w - v;
        } else {
            p->fC = 0;
            p->f4 = 0;
        }
        return 1;
    }
    n = p->f4 + 1;
    if (((p->f8 >= n) ? (int)p : func_L00_005382C8((int)p, n)) == 0) {
        return 0;
    }
    i = 0;
    p->f0[p->f4].v = 0;
    v = p->f0[0].v + w;
    p->f0[0].v = v;
    if (v < w) {
        do {
            i++;
            v = p->f0[i].v + 1;
            p->f0[i].v = v;
        } while (v == 0);
    }
    if (i >= p->f4) {
        p->f4 = p->f4 + 1;
    }
    return 1;
}
