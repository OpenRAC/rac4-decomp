/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern int func_L00_005382C8(int a1, int a2);

typedef struct Inner {
    s64 f0;
} Inner;

typedef struct Obj {
    Inner *p;
    s32 f4;
    s32 f8;
    s32 fC;
} Obj;

// Stores a 64-bit value in the object and sets a flag when that value is nonzero.
s32 func_L00_00538508(Obj *a0, Inner a1) {
    s32 i, n;

    if ((1 <= a0->f8 ? (int)a0 : func_L00_005382C8((int)a0, 2)) == 0) {
        return 0;
    }
    n = sizeof(Inner) / 8;
    a0->fC = 0;
    a0->f4 = 0;
    a0->p[0] = a1;
    if (a0->p[0].f0 != 0) {
        a0->f4 = 1;
    }
    for (i = 1; i < n; i++) {
        a1.f0 = 0;
        a0->p[i] = a1;
        if (a0->p[i].f0 != 0) {
            a0->f4 = i + 1;
        }
    }
    return 1;
}
